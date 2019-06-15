AM2320-WebGraph

---
English
---

I created a web graph that shows the value of the AM2320 sensor in arudino wifi module(ESP8266).
The AM2320 sensor is heated with a dryer and it is displayed in real time.

![demo](/docs/display_AM2320_sensor.gif)

# Description
I created this code for coding practice, becouse I would like to have checked about the process to display realtime Arduino's output by using WebSocket.

It display realtime information on the AM2320 thermo/hygro sensor connected to the ESP8266 on the client terminal browser.

This code supports the access point mode (AP mode) and the station mode (ST mode) as the operation of ESP8266.
The default is AP mode.
If you want to use in ST mode, put your access point information in "myssid" and "mypasswaord" in the code.
If there is access point specified at startup, it will connect automatically your access point.

※Because the ESP 8266 only supports 11b/g/n, the access point to connect needs to be connected to the 2.4 GHz band.

# Requirement
## Required device
### arudino wifi module(ESP8266)
If purchased in Japan, it works on the following boards:

- [電子太郎 ESP-WROOM-02開発ボード 2.4 GHz Wi-Fiモジュール MicroUSB](https://www.amazon.co.jp/gp/product/B071DY11SB/ref=as_li_tl?ie=UTF8&camp=247&creative=1211&creativeASIN=B071DY11SB&linkCode=as2&tag=shiguregaki02-22&linkId=131ae4b9a00ef3b7517980a81ed41d91)  
- [ＥＳＰ－ＷＲＯＯＭ－０２開発ボード](http://akizukidenshi.com/catalog/g/gK-12236/)
- [ESPr Developer（ESP-WROOM-02開発ボード）](https://www.switch-science.com/catalog/2500/)

### Digital Temperature and Humidity Sensor(AM2320)
If you purchase in Japan, you can purchase at Akizuki denshi.

- [温湿度センサ モジュール ＡＭ２３２０](http://akizukidenshi.com/catalog/g/gM-08663/)

If you purchase on a global site, you can also buy Alibaba or Banggood.com.

## Required software
The following software are required to be installed.

### Arduino IDE
Install Arduino IDE on your development PC.

[https://www.arduino.cc/en/Main/Software](https://www.arduino.cc/en/Main/Software)

### (tool) ESP8266 core for Arduino
The default configuration of the Arduino IDE does not support the ESP 8266 board.
Therefore, it is necessary to import **ESP8266 core for Arduino** into Arduino IDE.

[ESP8266 core for Arduino](https://github.com/esp8266/Arduino)

### (tool) Arduino ESP8266 filesystem uploader
It is file updater for Arduino ESP8266.
You can download it following URL link.

[Arduino ESP8266 filesystem uploader](https://github.com/esp8266/arduino-esp8266fs-plugin)

### (library) Links2004/arduinoWebSockets
WebSocket library for Arduino.
You can download it following URL link.

[Links2004/arduinoWebSockets](https://github.com/Links2004/arduinoWebSockets)

### (library) PaulStoffregen/Time
Time managemant library for Arduino.
You can download it following URL link.

[PaulStoffregen/Time](https://github.com/PaulStoffregen/Time)

### (library) hibikiledo/AM2320
It is a library that can control AM2320 sensor.
AM2320 is enable to get temperature and humidity information.
You can download it following URL link.

[hibikiledo/AM2320](https://github.com/hibikiledo/AM2320)

## Included software
The following software are NOT required to be installed, becuse there are included in code.
But, it is recommended to replace the latest version if it is available.

### Chart.js
Version used in code:2.8.0

You can download it following URL link.

[Chart.js](https://www.chartjs.org/)

### Moment.js
Version used in code:2.24.0

You can download it following URL link.

[Moment.js](https://momentjs.com/)

# Usage
### 1.Build the connection as the fllowing figure.

![connection_diagram](/docs/connection_diagram.jpg)

| Wire color | ESP8266 pin | AM2320 pin |
|:---|:---|:---|
|Red |3V3 |VDD |
|Yellow |GPIO4 |SDA |
|Black |GND |GND |
|White |GPIO5 |SCL |

The specification of AM2320 is referred to 
[Digital Temperature and Humidity Sensor AM2320 Product Manual](/docs/AM2320.pdf).

If use Wire.h, it seems that any GPIO pin of the ESP8266 is enabled to be used in I2C.
But I can not have run it in my enviroment.
So I reccomend that default I2C pins are used in SDA_PIN and SCL_PIN of ESC8266.

### 2.Install "Required software" in Arduino IDE.
"Required software" is [link](#required-software)

### 3.Write this code on the ESP8266 board with Arduino IDE.
The code to write is "AM2320-WebGraph.ino".

The parameters are below. Please change as appropriate for your environment.

| Parameters | Description | Default value |
|:---|:---|:---|
|ssid |The name of SSID in case used AP-Mode. |"ESP8266 Access Point" |
|password |The password in case used AP-Mode. |"esp8266-test" |
|myssid |The name of SSID in case used ST-Mode.  Please change as appropriate for your environment. |"The ssid name of your AP" |
|mypassword |The password in case used ST-Mode.  Please change as appropriate for your environment. |"The password of your AP" |
|CPU_MHZ |ESP8266 CPU frequency.  Please change as appropriate for your environment. |160 |
|SDA_PIN ※ |The number of GPIO pin on ESP8266 connected to AM2320 SDA pin. |4 |
|SCL_PIN ※ |The number of GPIO pin on ESP8266 connected to AM2320 SCL pin. |5 |
|READ_INTERVAL ※※ |The interval time to read AM2320 sensor.(Any one of 1s, 5s, 30s, 60s and 300s) |5 |

※ If use Wire.h, it seems that any GPIO pin of the ESP8266 is enabled to be used in I2C.
But I can not have run it in my enviroment.
So I reccomend that default I2C pins are used in SDA_PIN and SCL_PIN of ESC8266.

※※ The interval time to read AM2320 sensor is fixed as 5 patterns.(Any one of 1s, 5s, 30s, 60s and 300s)
So entering any other value may cause problems.

### 4.Uploade files for webserver to ESP8266.
Use the Arduino ESP8266 filesystem uploader.
It will automatically read / upload data from the source code directory.

The files to upload is below.

| File | Description |
|:---|:---|
|Chart.min.js.gz |OSS script used to draw graphs |
|index.html.gz |Specify the screen when accessing HTML |
|main.css.gz |Specify screen design |
|moment.min.js.gz |OSS script used to manage time |
|WebSocket.js.gz |Specify the client operation of WebSocket |

All files are compressed with ".gz" to reduce file size.
The code is written to work without compression.

### 5.Turn on the ESP8266 board and configure the wifi settings.

#### In AP-Mode(default): 
ESP8266 waits to connect ST-device.
SSID name is "ESP8266 Access Point", and password is "esp8266-test".
If access is sucsess, the IP address of the access destination is output with "[info] Access destination IP address: XXXX" on serial monitor.

![Capture_connect_AP](/docs/Capture_connect_AP.png)

※If you change "ssid" and "password" in the code, SSID name and password are changed to input value.

#### In ST-Mode: 
ESP8266 automatically connects to access point.
If access is sucsess, the IP address of the access destination is output with "[info] Access destination IP address: XXXX" on serial monitor.

![Capture_connect_ST](/docs/Capture_connect_ST.png)

※Because the ESP 8266 only supports 11b/g/n, the access point to connect needs to be connected to the 2.4 GHz band.

### 6.Access the IP address of the access destination from the browser of the cliebt terminal.
If you input the IP address of the access destinatio in browser search form, you will show the screen to display temperature and humidity.

![display_capture](/docs/display_capture.png)

#### Screen description:
The blue background at the top shows real-time temperature and humidity values.
The history of past temperature and humidity information is displayed at the graph.

The interval radio button allows you to change the update time of temperature and humidity information.
(Only 1s, 5s, 30s, 60s and 300s)

The Reset graph button allows you to reset the graph.

# Licence
[MIT](/LICENSE)

# Author
[shiguregaki](https://github.com/shiguregaki)

---
Japanese
---

このコードはarudino wifiモジュールのESP8266でAM2320をWebグラフ化するものです。
AM2320センサーをドライヤーで温めており、それがリアルタイムに表示されています。

![demo](/docs/display_AM2320_sensor.gif)

# 概要
WebSocketでクライアント端末にデータを送信して、ブラウザ上でリアルタイムに表示する処理のコーディング練習用に本コードを作成しました。

ESP8266に接続しているAM2320という温湿度センサーの情報をリアルタイムにクライアント端末側のブラウザで表示させます。

このコードはESP8266の動作として、アクセスポイントモード(AP-Mode)とステーションモード(ST-Mode)をサポートしています。
デフォルトではAP-Modeとなります。
ST-Modeで使用したい場合は、コード内にある"myssid"と"mypassword"にご自分のアクセスポイントの情報を入れてください。
起動時に指定されたアクセスポイントがあれば自動で接続します。

※ESP8266が11b/g/nしかサポートしていないため、接続先のアクセスポイントは2.4GHz帯のものに接続する必要があります。

# 必要なこと
## 必要なデバイス
### arudino wifi module(ESP8266)
日本での購入なら、以下のボード上で動作します。

- [電子太郎 ESP-WROOM-02開発ボード 2.4 GHz Wi-Fiモジュール MicroUSB](https://www.amazon.co.jp/gp/product/B071DY11SB/ref=as_li_tl?ie=UTF8&camp=247&creative=1211&creativeASIN=B071DY11SB&linkCode=as2&tag=shiguregaki02-22&linkId=131ae4b9a00ef3b7517980a81ed41d91)  
- [ＥＳＰ－ＷＲＯＯＭ－０２開発ボード](http://akizukidenshi.com/catalog/g/gK-12236/)
- [ESPr Developer（ESP-WROOM-02開発ボード）](https://www.switch-science.com/catalog/2500/)

### Digital Temperature and Humidity Sensor(AM2320)
日本での購入なら、秋月電子通商で購入できます。

- [温湿度センサ モジュール ＡＭ２３２０](http://akizukidenshi.com/catalog/g/gM-08663/)

グローバルなサイトで購入なら、AlibabaやBanggood.comなどでも購入できます。

## インストールが必要なソフトウェア
### Arduino IDE
開発用のPCにArduino IDEをインストールします。

[https://www.arduino.cc/en/Main/Software](https://www.arduino.cc/en/Main/Software)

### (tool) ESP8266 core for Arduino
Arduino IDEのデフォルト設定では、ESP8266ボードはサポートされていません。
そのため、**ESP8266 core for Arduino**をArduino IDEにインポートする必要があります。

[ESP8266 core for Arduino](https://github.com/esp8266/Arduino)

### (tool) Arduino ESP8266 filesystem uploader
Arduino ESP8266用のファイルアップローダーです。
以下のサイトからダウンロードできます。

[Arduino ESP8266 filesystem uploader](https://github.com/esp8266/arduino-esp8266fs-plugin)

### (library) Links2004/arduinoWebSockets
Arduino向けのWebSocketライブラリーです。
以下のサイトからダウンロードできます。

[Links2004/arduinoWebSockets](https://github.com/Links2004/arduinoWebSockets)

### (library) PaulStoffregen/Time
Arduino上で時刻管理するためのライブラリーです。
以下のサイトからダウンロードできます。

[PaulStoffregen/Time](https://github.com/PaulStoffregen/Time)

### (library) hibikiledo/AM2320
AM2320センサーを制御できるライブラリーです。
温度や湿度情報を取得できます。

[hibikiledo/AM2320](https://github.com/hibikiledo/AM2320)

## 利用しているソフトウェア
以下のソフトウェアはソースコード内に組み込まれています。
そのため、インストールは必要はありませんが、最新版のものがあれば別途置き換えて利用することをお勧めします。

### Chart.js
ソースコードで利用しているバージョン：2.8.0

以下のサイトからダウンロードできます。

[Chart.js](https://www.chartjs.org/)

### Moment.js
ソースコードで利用しているバージョン：2.24.0

以下のサイトからダウンロードできます。

[Moment.js](https://momentjs.com/)


# 使い方
### 1.以下のように回路を組みます。

![connection_diagram](/docs/connection_diagram.jpg)

| ワイヤの色 | ESP8266端子 | AM2320端子 |
|:---|:---|:---|
|赤 |3V3 |VDD |
|黄 |GPIO4 |SDA |
|黒 |GND |GND |
|白 |GPIO5 |SCL |

AM2320の仕様は
[Digital Temperature and Humidity Sensor AM2320 Product Manual](/docs/AM2320.pdf)
を参照

Wire.hライブラリを使えば、ESP8266の任意のGPIOピンをI2Cで利用できるようです。
しかし、自分の環境ではうまく動きませんでした。
そのため、SDA_PINとSCL_PINはESP8266のデフォルトI2Cピンにすることをお勧めします。

### 2.Arduino IDEに"インストールが必要なソフトウェア"をインストールします。
インストールが必要なソフトウェアは[こちら](#インストールが必要なソフトウェア)

### 3.Arduino IDEでESP8266基板に本コードを書き込みます。
書き込むコードは「AM2320-WebGraph.ino」です。

パラメータは以下です。ご自分の環境に合わせて適宜変更してください。

| パラメータ | 説明 | デフォルト値 |
|:---|:---|:---|
|ssid |AP-Modeで使う場合のAPのSSID |"ESP8266 Access Point" |
|password |AP-Modeで使う場合のAPのパスワード |"esp8266-test" |
|myssid |ST-Modeで使う場合のAPのSSID。ご自分の環境に合わせて設定してください。 |"The ssid name of your AP" |
|mypassword |ST-Modeで使う場合のAPのパスワード。ご自分の環境に合わせて設定してください。 |"The password of your AP" |
|CPU_MHZ |ESP8266のCPU周波数。ご自分の環境に合わせて設定してください。 |160 |
|SDA_PIN ※ |AM2320のSDA端子と接続するESP8266側のGPIOピン番号 |4 |
|SCL_PIN ※ |AM2320のSCL端子と接続するESP8266側のGPIOピン番号 |5 |
|READ_INTERVAL ※※ |AM2320センサーの読み取り間隔。(1s,5s,30s,60s,300sのどれか) |5 |

※ Wire.hライブラリを使えば、ESP8266の任意のGPIOピンをI2Cで利用できるようです。
しかし、自分の環境ではうまく動きませんでした。
そのため、SDA_PINとSCL_PINはESP8266のデフォルトI2Cピンにすることをお勧めします。

※※ AM2320センサーの読み取り間隔はクライアント端末側で固定の5パターンしか設定できないようにしています。
(1s,5s,30s,60s,300sのどれか)
そのため、それ以外の値を入れると不具合が発生する可能性があります。

### 4.ESP8266基板にWebサーバ用ファイルをアップロードします。

Arduino ESP8266 filesystem uploaderを使えば、自動でソースコードがあるディレクトリ内にある/dataを読み取り、アップロードしてくれます。

アップロードするコードは以下です。

| 名称 | 説明 |
|:---|:---|
|Chart.min.js.gz |JavaScriptでグラフ描画するために使用しているOSSスクリプト |
|index.html.gz |HTMLアクセスしたときの画面を指定 |
|main.css.gz |画面デザインを指定 |
|moment.min.js.gz |JavaScriptで時刻管理するために使用しているOSSスクリプト |
|WebSocket.js.gz |WebSoketのクライアント側の動作を指定 |

ファイルサイズを小さくするために、全ファイルを".gz"で圧縮しています。
圧縮しなくても動くようにコードは書いています。

### 5.ESP8266基板の電源を入れて、wifiの設定をします。
#### AP-Modeの場合(デフォルト):
アクセスポイントにST端末がつながるのを待っています。
アクセスポイントのSSIDは「ESP8266 Access Point」、パスワードは「esp8266-test」です。
シリアルモニタでは接続が成功すれば、以下のように「[info] Access destination IP address: XXXX」のようにアクセス先のIPアドレスが出力されます。

![Capture_connect_AP](/docs/Capture_connect_AP.png)

※もし、コードのssidとpasswordを変えていたら、その値に変わっています。

#### ST-Modeの場合:
自動でアクセスポイントに接続します。
シリアルモニタでは接続が成功すれば、以下のように「[info] Access destination IP address: XXXX」のようにアクセス先のIPアドレスが出力されます。

![Capture_connect_ST](/docs/Capture_connect_ST.png)

※ESP8266が11b/g/nしかサポートしていないため、接続先のアクセスポイントは2.4GHz帯のものに接続する必要があります。

### 6.クライアント端末のブラウザからアクセス先のIPアドレスにアクセスします。
ブラウザの検索フォームのところに、アクセス先のIPアドレス"X.X.X.X"を入力すれば温度と湿度を表示する画面が表示されるはずです。

![display_capture](/docs/display_capture.png)

#### 画面の説明:
上部にある青背景部分にリアルタイムの温度と湿度値を表示されます。
グラフのところにこれまでの温度と湿度情報の履歴が表示されます。

intervalラジオボタンでは、温湿度情報の更新時間を変更できます。(1s,5s,30s,60s,300sのみ)

Reset graphボタンをクリックすると、グラフがリセットされます。


# ライセンス
[MIT](/LICENSE)

# 作成者
[shiguregaki](https://github.com/shiguregaki)
