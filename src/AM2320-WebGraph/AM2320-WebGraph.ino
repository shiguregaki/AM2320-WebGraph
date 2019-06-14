#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>
#include <ESP8266WebServer.h>
#include <FS.h>
#include <WebSocketsServer.h>
#include <TimeLib.h>
#include <AM2320.h>
#include <Ticker.h>

/************************************************ PARAMETERS ************************************************/

/* If you use this program as AP, set any ssid name and password. */
const char *ssid = "ESP8266 Access Point";
const char *password = "esp8266-test";

/* If you use this program as ST, set the ssid name and password of your AP.
   If you does NOT set following parameter, this program run as AP.*/
const char *myssid = "The ssid name of your AP";
const char *mypassword = "The password of your AP";

#define CPU_MHZ                       160         // CPU frequency (MHz)
#define SDA_PIN                         4         // Set SDA pin of AM2320.
#define SCL_PIN                         5         // Set SCL pin of AM2320.
#define READ_INTERVAL                   5         // Set interval time to read sensor (seconds)


/************************************************ SYSTME PARAMETERS ************************************************/
ESP8266WiFiMulti wifiMulti;
ESP8266WebServer server(80);
WebSocketsServer webSocket(81);
AM2320 am2320;
Ticker timer;
bool setUpTimeIsComplete = false;
float thermo_f = 0;
float hygro_f = 0;
uint32_t currentSendInterval;
bool sendCurrentSendInterval(int8_t num = -1);

/************************************************ SETUP ************************************************/

void setup() {
  // set serial monitor.
  Serial.begin(115200);
  delay(10);
  Serial.println("\r\n");

  // Execute SETUP_FUNCTIONS.
  setupWiFi();
  setupSPIFFS();
  setupWebSocket();
  setupServer();
  setupTimer();
  setupAm2320();
}

/************************************************ LOOP ************************************************/

void loop() {
  webSocket.loop();
  server.handleClient();
}

/************************************************ SETUP_FUNCTIONS ************************************************/

/* Set up Wi-Fi AP or ST.
   Default running is AP mode, but if your Wi-Fi AP is found, this program run as ST mode. */
void setupWiFi() {
  Serial.println("[info] Execute setupWiFi() function.");
  WiFi.softAP(ssid, password);
  wifiMulti.addAP(myssid, mypassword);

  // Wait for the Wi-Fi to connect.
  Serial.println("[info] Connecting");
  while (wifiMulti.run() != WL_CONNECTED && WiFi.softAPgetStationNum() < 1) {
    delay(250);
    Serial.print('.');
  }
  Serial.println("\r\n");

  // Check AP or ST mode.
  if(WiFi.softAPgetStationNum() == 0) {
    Serial.println("[info] Run as ST mode.");
    Serial.print("[info] Access destination IP address:\t");
    Serial.println(WiFi.localIP());
  } else {
    Serial.println("[info] Run as AP mode.");
    Serial.print("[info] Access destination IP address:\t");
    Serial.println(WiFi.softAPIP());
  }
  Serial.println("[info] Wi-Fi setup was complete.");Serial.println("");
}

/* Set up SPI Flash File System (SPIFFS). */
void setupSPIFFS() {
  Serial.println("[info] Execute setupSPIFFS() function.");
  SPIFFS.begin();
  Serial.println("[info] SPIFFS contents:");
  Dir dir = SPIFFS.openDir("/");
  while (dir.next()) {
    String fileName = dir.fileName();
    size_t fileSize = dir.fileSize();
    Serial.printf("\tFile name: %s, size: %s\r\n", fileName.c_str(), formatBytes(fileSize).c_str());
  }
  Serial.println("[info] SPI Flash File System (SPIFFS) setup was complete.");Serial.println("");
}

/* Set up WebSocket server. */
void setupWebSocket() {
  Serial.println("[info] Execute setupWebSocket() function.");
  webSocket.begin();
  webSocket.onEvent(webSocketEvent); // Register handler.
  Serial.println("[info] WebSocket server setup was complete.");Serial.println("");
}

/* Set up WebSocket server.  */
void setupServer() {
  Serial.println("[info] Execute setupServer() function.");
  server.onNotFound(handleRoot); // Register handler.
  server.begin();
  Serial.println("[info] HTTP server setup was complete.");Serial.println("");
}

/* Set up Timer.  */
void setupTimer(){
  Serial.println("[info] Execute setupTimer() function.");
  setTime(00, 00, 00, 1, 1, 1970);
  currentSendInterval = READ_INTERVAL;
  timer.attach(currentSendInterval, read_sensor);
  Serial.println("[info] Timer setup was complete.");Serial.println("");
}

/* Set up AM2320 sensor.  */
void setupAm2320(){
  Serial.println("[info] Execute setupAm2320() function.");
  delay(50);
  am2320.begin(SDA_PIN, SCL_PIN);
  Serial.println("[info] AM2320 setup was complete.");Serial.println("");
}

/************************************************ SERVER_HANDLERS ************************************************/

/* If abnormal site access is detected, return to 404 page.
   The site access destination is judged true or false in this handler.*/
void handleRoot(){
  if(!handleFileRead(server.uri())){
    server.send(404, "text/plain", "404: File Not Found");
    Serial.println("[warn] Detect abnormal URL access.");
  }
}

/* If normal site access is detected, return to requested file. */
bool handleFileRead(String path) {
  Serial.println("[info] handleFileRead: " + path);
  if (path.endsWith("/")) path += "index.html";
  if (existFile(path)) {
    String filepath = getFilePath(path);
    File file = SPIFFS.open(filepath, "r");
    size_t sent = server.streamFile(file, getContentType(path));
    file.close();
    Serial.println(String("\tSent file: ") + path);
    return true;
  }
  Serial.println(String("\tFile Not Found: ") + path);
  return false;
}

/* If WebSocket message is received, execute processing according to the data. */
void webSocketEvent(uint8_t num, WStype_t type, uint8_t * payload, size_t lenght) {
  switch (type) {
    case WStype_DISCONNECTED:
      Serial.printf("[warn] [%u] Disconnected!\n", num);
      if(webSocket.connectedClients() <= 0) setUpTimeIsComplete = false;
      break;
    case WStype_CONNECTED:{
      IPAddress ip = webSocket.remoteIP(num);
      Serial.printf("[info] [%u] Connected from %d.%d.%d.%d url: %s\n", num, ip[0], ip[1], ip[2], ip[3], payload);
      // Send currentSendInterval to client.
      sendCurrentSendInterval(num);
    }
      break;
    case WStype_TEXT:{
      Serial.printf("[info] [%u] get Text: %s\n", num, payload);
      // Set the time only at the first connection.
      if (!setUpTimeIsComplete && payload[0]=='C' && payload[1]=='o' && payload[2]=='n' && payload[3]=='n' && payload[4] =='e' && payload[5] =='c' && payload[6] =='t'){
        String time_str[6] = {"\0"};
        uint32_t time_uint[6];
        int32_t index = split((const char *) &payload[8], ',', time_str);
        for(int32_t i = 0; i < index; i++){
          time_uint[i] = (uint32_t) strtol(time_str[i].c_str(), NULL, 10);
        }
        setTime(time_uint[3], time_uint[4], time_uint[5] , time_uint[2], time_uint[1], time_uint[0]);
        Serial.printf("[info] setTime: %d/%d/%d %d:%d:%d\n", time_uint[0], time_uint[1], time_uint[2], time_uint[3], time_uint[4], time_uint[5] );
        setUpTimeIsComplete = true;
      }else if(payload[0] == '#'){
        currentSendInterval = (uint32_t) strtol((const char *) &payload[1], NULL, 10);
        Serial.printf("[info] setIntervalTime: %d\n", currentSendInterval);
        timer.detach();
        timer.attach(currentSendInterval, read_sensor);
        // Send currentSendInterval to connected client.
        sendCurrentSendInterval();
      }
    }
      break;
  }
}

/************************************************ SENSOR_HANDLERS ************************************************/
void read_sensor (void) {
  // Measure temperature and humidity.
  if(webSocket.connectedClients() > 0){
    if(am2320.measure()){
      thermo_f = am2320.getTemperature();
      hygro_f = am2320.getHumidity();
      // Send measured data to client. (content is JSON type)
      String sendData_json = "{ \"time\": \""
                             + String(year())
                             + '/'
                             + String(month())
                             + '/'
                             + String(day())
                             + ' '
                             + String(hour())
                             + ':'
                             + String(minute())
                             + ':'
                             + String(second())
                             + "\", \"thermo\": \""
                             + String(thermo_f)
                             + "\", \"hygro\": \""
                             + String(hygro_f)
                             + "\" }";
      Serial.print("[info] sendData_json, measured data: ");
      Serial.println(sendData_json);
      webSocket.broadcastTXT((const char *) sendData_json.c_str());
    }else{
      int32_t errorCode = am2320.getErrorCode();
      switch (errorCode) {
        case 1: Serial.println("[err] Sensor is offline"); break;
        case 2: Serial.println("[err] CRC validation failed."); break;
        default: Serial.println("[err] Unexpected measurement error occurs."); break;
      }
    }
  }
}


/************************************************ HELPER_FUNCTIONS ************************************************/

/* Convert sizes in bytes to KB and MB. */
String formatBytes(size_t bytes) {
  if (bytes < 1024) {
    return String(bytes) + "B";
  } else if (bytes < (1024 * 1024)) {
    return String(bytes / 1024.0) + "KB";
  } else if (bytes < (1024 * 1024 * 1024)) {
    return String(bytes / 1024.0 / 1024.0) + "MB";
  }
}

/* Return the filetype from filename. */
String getContentType(String filename) {
  if(server.hasArg("download")) return "application/octet-stream";
  else if(filename.endsWith(".htm")) return "text/html";
  else if(filename.endsWith(".html")) return "text/html";
  else if(filename.endsWith(".css")) return "text/css";
  else if(filename.endsWith(".js")) return "application/javascript";
  else if(filename.endsWith(".png")) return "image/png";
  else if(filename.endsWith(".gif")) return "image/gif";
  else if(filename.endsWith(".jpg")) return "image/jpeg";
  else if(filename.endsWith(".ico")) return "image/x-icon";
  else if(filename.endsWith(".xml")) return "text/xml";
  else if(filename.endsWith(".pdf")) return "application/x-pdf";
  else if(filename.endsWith(".zip")) return "application/x-zip";
  else if(filename.endsWith(".gz")) return "application/x-gzip";
  return "text/plain";
}

/* Return boolean whether file exists. */
bool existFile(String path) {
  String pathWithGz = path + ".gz";
  if(SPIFFS.exists(pathWithGz) || SPIFFS.exists(path)) return true;
  return false;
}

/* Return the suitable file path.
   If compressed file exists, return preferentially its filepath.*/
String getFilePath(String path) {
  String pathWithGz = path + ".gz";
  if(SPIFFS.exists(pathWithGz)) return pathWithGz;
  return path;
}

/* Split string per delimiter. */
int32_t split(String data, char delimiter, String *dst){
    int32_t index = 0;
    int32_t arraySize = (sizeof(data)/sizeof((data)[0]));  
    int32_t datalength = data.length();
    for (int32_t i = 0; i < datalength; i++) {
        char tmp = data.charAt(i);
        if ( tmp == delimiter ) {
            index++;
            if ( index > (arraySize - 1)) return -1;
        }
        else dst[index] += tmp;
    }
    return (index + 1);
}

/* Send current interval time to send to WebSocket cliant. 
   If num is negative or not value, it will broadcast.*/
bool sendCurrentSendInterval(int8_t num){
  bool ret = false;
  String sendData_json = "{ \"currentSendInterval\": \""
                          + String(currentSendInterval)
                          + "\" }";
  Serial.printf("[info] sendData_json, currentSendInterval[num=%d]: ",num);
  Serial.println(sendData_json);
  if(num<0){
    ret = webSocket.broadcastTXT((const char *) sendData_json.c_str());
  }else{
    ret = webSocket.sendTXT(num, (const char *) sendData_json.c_str());
  }
  return ret;
}
