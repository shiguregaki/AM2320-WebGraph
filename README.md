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

��Because the ESP 8266 only supports 11b/g/n, the access point to connect needs to be connected to the 2.4 GHz band.

# Requirement
## Required device
### arudino wifi module(ESP8266)
If purchased in Japan, it works on the following boards:

- [�d�q���Y ESP-WROOM-02�J���{�[�h 2.4 GHz Wi-Fi���W���[�� MicroUSB](https://www.amazon.co.jp/gp/product/B071DY11SB/ref=as_li_tl?ie=UTF8&camp=247&creative=1211&creativeASIN=B071DY11SB&linkCode=as2&tag=shiguregaki02-22&linkId=131ae4b9a00ef3b7517980a81ed41d91)  
- [�d�r�o�|�v�q�n�n�l�|�O�Q�J���{�[�h](http://akizukidenshi.com/catalog/g/gK-12236/)
- [ESPr Developer�iESP-WROOM-02�J���{�[�h�j](https://www.switch-science.com/catalog/2500/)

### Digital Temperature and Humidity Sensor(AM2320)
If you purchase in Japan, you can purchase at Akizuki denshi.

- [�����x�Z���T ���W���[�� �`�l�Q�R�Q�O](http://akizukidenshi.com/catalog/g/gM-08663/)

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
|SDA_PIN �� |The number of GPIO pin on ESP8266 connected to AM2320 SDA pin. |4 |
|SCL_PIN �� |The number of GPIO pin on ESP8266 connected to AM2320 SCL pin. |5 |
|READ_INTERVAL ���� |The interval time to read AM2320 sensor.(Any one of 1s, 5s, 30s, 60s and 300s) |5 |

�� If use Wire.h, it seems that any GPIO pin of the ESP8266 is enabled to be used in I2C.
But I can not have run it in my enviroment.
So I reccomend that default I2C pins are used in SDA_PIN and SCL_PIN of ESC8266.

���� The interval time to read AM2320 sensor is fixed as 5 patterns.(Any one of 1s, 5s, 30s, 60s and 300s)
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

��If you change "ssid" and "password" in the code, SSID name and password are changed to input value.

#### In ST-Mode: 
ESP8266 automatically connects to access point.
If access is sucsess, the IP address of the access destination is output with "[info] Access destination IP address: XXXX" on serial monitor.

![Capture_connect_ST](/docs/Capture_connect_ST.png)

��Because the ESP 8266 only supports 11b/g/n, the access point to connect needs to be connected to the 2.4 GHz band.

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

���̃R�[�h��arudino wifi���W���[����ESP8266��AM2320��Web�O���t��������̂ł��B
AM2320�Z���T�[���h���C���[�ŉ��߂Ă���A���ꂪ���A���^�C���ɕ\������Ă��܂��B

![demo](/docs/display_AM2320_sensor.gif)

# �T�v
WebSocket�ŃN���C�A���g�[���Ƀf�[�^�𑗐M���āA�u���E�U��Ń��A���^�C���ɕ\�����鏈���̃R�[�f�B���O���K�p�ɖ{�R�[�h���쐬���܂����B

ESP8266�ɐڑ����Ă���AM2320�Ƃ��������x�Z���T�[�̏������A���^�C���ɃN���C�A���g�[�����̃u���E�U�ŕ\�������܂��B

���̃R�[�h��ESP8266�̓���Ƃ��āA�A�N�Z�X�|�C���g���[�h(AP-Mode)�ƃX�e�[�V�������[�h(ST-Mode)���T�|�[�g���Ă��܂��B
�f�t�H���g�ł�AP-Mode�ƂȂ�܂��B
ST-Mode�Ŏg�p�������ꍇ�́A�R�[�h���ɂ���"myssid"��"mypassword"�ɂ������̃A�N�Z�X�|�C���g�̏������Ă��������B
�N�����Ɏw�肳�ꂽ�A�N�Z�X�|�C���g������Ύ����Őڑ����܂��B

��ESP8266��11b/g/n�����T�|�[�g���Ă��Ȃ����߁A�ڑ���̃A�N�Z�X�|�C���g��2.4GHz�т̂��̂ɐڑ�����K�v������܂��B

# �K�v�Ȃ���
## �K�v�ȃf�o�C�X
### arudino wifi module(ESP8266)
���{�ł̍w���Ȃ�A�ȉ��̃{�[�h��œ��삵�܂��B

- [�d�q���Y ESP-WROOM-02�J���{�[�h 2.4 GHz Wi-Fi���W���[�� MicroUSB](https://www.amazon.co.jp/gp/product/B071DY11SB/ref=as_li_tl?ie=UTF8&camp=247&creative=1211&creativeASIN=B071DY11SB&linkCode=as2&tag=shiguregaki02-22&linkId=131ae4b9a00ef3b7517980a81ed41d91)  
- [�d�r�o�|�v�q�n�n�l�|�O�Q�J���{�[�h](http://akizukidenshi.com/catalog/g/gK-12236/)
- [ESPr Developer�iESP-WROOM-02�J���{�[�h�j](https://www.switch-science.com/catalog/2500/)

### Digital Temperature and Humidity Sensor(AM2320)
���{�ł̍w���Ȃ�A�H���d�q�ʏ��ōw���ł��܂��B

- [�����x�Z���T ���W���[�� �`�l�Q�R�Q�O](http://akizukidenshi.com/catalog/g/gM-08663/)

�O���[�o���ȃT�C�g�ōw���Ȃ�AAlibaba��Banggood.com�Ȃǂł��w���ł��܂��B

## �C���X�g�[�����K�v�ȃ\�t�g�E�F�A
### Arduino IDE
�J���p��PC��Arduino IDE���C���X�g�[�����܂��B

[https://www.arduino.cc/en/Main/Software](https://www.arduino.cc/en/Main/Software)

### (tool) ESP8266 core for Arduino
Arduino IDE�̃f�t�H���g�ݒ�ł́AESP8266�{�[�h�̓T�|�[�g����Ă��܂���B
���̂��߁A**ESP8266 core for Arduino**��Arduino IDE�ɃC���|�[�g����K�v������܂��B

[ESP8266 core for Arduino](https://github.com/esp8266/Arduino)

### (tool) Arduino ESP8266 filesystem uploader
Arduino ESP8266�p�̃t�@�C���A�b�v���[�_�[�ł��B
�ȉ��̃T�C�g����_�E�����[�h�ł��܂��B

[Arduino ESP8266 filesystem uploader](https://github.com/esp8266/arduino-esp8266fs-plugin)

### (library) Links2004/arduinoWebSockets
Arduino������WebSocket���C�u�����[�ł��B
�ȉ��̃T�C�g����_�E�����[�h�ł��܂��B

[Links2004/arduinoWebSockets](https://github.com/Links2004/arduinoWebSockets)

### (library) PaulStoffregen/Time
Arduino��Ŏ����Ǘ����邽�߂̃��C�u�����[�ł��B
�ȉ��̃T�C�g����_�E�����[�h�ł��܂��B

[PaulStoffregen/Time](https://github.com/PaulStoffregen/Time)

### (library) hibikiledo/AM2320
AM2320�Z���T�[�𐧌�ł��郉�C�u�����[�ł��B
���x�⎼�x�����擾�ł��܂��B

[hibikiledo/AM2320](https://github.com/hibikiledo/AM2320)

## ���p���Ă���\�t�g�E�F�A
�ȉ��̃\�t�g�E�F�A�̓\�[�X�R�[�h���ɑg�ݍ��܂�Ă��܂��B
���̂��߁A�C���X�g�[���͕K�v�͂���܂��񂪁A�ŐV�ł̂��̂�����Εʓr�u�������ė��p���邱�Ƃ������߂��܂��B

### Chart.js
�\�[�X�R�[�h�ŗ��p���Ă���o�[�W�����F2.8.0

�ȉ��̃T�C�g����_�E�����[�h�ł��܂��B

[Chart.js](https://www.chartjs.org/)

### Moment.js
�\�[�X�R�[�h�ŗ��p���Ă���o�[�W�����F2.24.0

�ȉ��̃T�C�g����_�E�����[�h�ł��܂��B

[Moment.js](https://momentjs.com/)


# �g����
### 1.�ȉ��̂悤�ɉ�H��g�݂܂��B

![connection_diagram](/docs/connection_diagram.jpg)

| ���C���̐F | ESP8266�[�q | AM2320�[�q |
|:---|:---|:---|
|�� |3V3 |VDD |
|�� |GPIO4 |SDA |
|�� |GND |GND |
|�� |GPIO5 |SCL |

AM2320�̎d�l��
[Digital Temperature and Humidity Sensor AM2320 Product Manual](/docs/AM2320.pdf)
���Q��

Wire.h���C�u�������g���΁AESP8266�̔C�ӂ�GPIO�s����I2C�ŗ��p�ł���悤�ł��B
�������A�����̊��ł͂��܂������܂���ł����B
���̂��߁ASDA_PIN��SCL_PIN��ESP8266�̃f�t�H���gI2C�s���ɂ��邱�Ƃ������߂��܂��B

### 2.Arduino IDE��"�C���X�g�[�����K�v�ȃ\�t�g�E�F�A"���C���X�g�[�����܂��B
�C���X�g�[�����K�v�ȃ\�t�g�E�F�A��[������](#�C���X�g�[�����K�v�ȃ\�t�g�E�F�A)

### 3.Arduino IDE��ESP8266��ɖ{�R�[�h���������݂܂��B
�������ރR�[�h�́uAM2320-WebGraph.ino�v�ł��B

�p�����[�^�͈ȉ��ł��B�������̊��ɍ��킹�ēK�X�ύX���Ă��������B

| �p�����[�^ | ���� | �f�t�H���g�l |
|:---|:---|:---|
|ssid |AP-Mode�Ŏg���ꍇ��AP��SSID |"ESP8266 Access Point" |
|password |AP-Mode�Ŏg���ꍇ��AP�̃p�X���[�h |"esp8266-test" |
|myssid |ST-Mode�Ŏg���ꍇ��AP��SSID�B�������̊��ɍ��킹�Đݒ肵�Ă��������B |"The ssid name of your AP" |
|mypassword |ST-Mode�Ŏg���ꍇ��AP�̃p�X���[�h�B�������̊��ɍ��킹�Đݒ肵�Ă��������B |"The password of your AP" |
|CPU_MHZ |ESP8266��CPU���g���B�������̊��ɍ��킹�Đݒ肵�Ă��������B |160 |
|SDA_PIN �� |AM2320��SDA�[�q�Ɛڑ�����ESP8266����GPIO�s���ԍ� |4 |
|SCL_PIN �� |AM2320��SCL�[�q�Ɛڑ�����ESP8266����GPIO�s���ԍ� |5 |
|READ_INTERVAL ���� |AM2320�Z���T�[�̓ǂݎ��Ԋu�B(1s,5s,30s,60s,300s�̂ǂꂩ) |5 |

�� Wire.h���C�u�������g���΁AESP8266�̔C�ӂ�GPIO�s����I2C�ŗ��p�ł���悤�ł��B
�������A�����̊��ł͂��܂������܂���ł����B
���̂��߁ASDA_PIN��SCL_PIN��ESP8266�̃f�t�H���gI2C�s���ɂ��邱�Ƃ������߂��܂��B

���� AM2320�Z���T�[�̓ǂݎ��Ԋu�̓N���C�A���g�[�����ŌŒ��5�p�^�[�������ݒ�ł��Ȃ��悤�ɂ��Ă��܂��B
(1s,5s,30s,60s,300s�̂ǂꂩ)
���̂��߁A����ȊO�̒l������ƕs�����������\��������܂��B

### 4.ESP8266���Web�T�[�o�p�t�@�C�����A�b�v���[�h���܂��B

Arduino ESP8266 filesystem uploader���g���΁A�����Ń\�[�X�R�[�h������f�B���N�g�����ɂ���/data��ǂݎ��A�A�b�v���[�h���Ă���܂��B

�A�b�v���[�h����R�[�h�͈ȉ��ł��B

| ���� | ���� |
|:---|:---|
|Chart.min.js.gz |JavaScript�ŃO���t�`�悷�邽�߂Ɏg�p���Ă���OSS�X�N���v�g |
|index.html.gz |HTML�A�N�Z�X�����Ƃ��̉�ʂ��w�� |
|main.css.gz |��ʃf�U�C�����w�� |
|moment.min.js.gz |JavaScript�Ŏ����Ǘ����邽�߂Ɏg�p���Ă���OSS�X�N���v�g |
|WebSocket.js.gz |WebSoket�̃N���C�A���g���̓�����w�� |

�t�@�C���T�C�Y�����������邽�߂ɁA�S�t�@�C����".gz"�ň��k���Ă��܂��B
���k���Ȃ��Ă������悤�ɃR�[�h�͏����Ă��܂��B

### 5.ESP8266��̓d�������āAwifi�̐ݒ�����܂��B
#### AP-Mode�̏ꍇ(�f�t�H���g):
�A�N�Z�X�|�C���g��ST�[�����Ȃ���̂�҂��Ă��܂��B
�A�N�Z�X�|�C���g��SSID�́uESP8266 Access Point�v�A�p�X���[�h�́uesp8266-test�v�ł��B
�V���A�����j�^�ł͐ڑ�����������΁A�ȉ��̂悤�Ɂu[info] Access destination IP address: XXXX�v�̂悤�ɃA�N�Z�X���IP�A�h���X���o�͂���܂��B

![Capture_connect_AP](/docs/Capture_connect_AP.png)

�������A�R�[�h��ssid��password��ς��Ă�����A���̒l�ɕς���Ă��܂��B

#### ST-Mode�̏ꍇ:
�����ŃA�N�Z�X�|�C���g�ɐڑ����܂��B
�V���A�����j�^�ł͐ڑ�����������΁A�ȉ��̂悤�Ɂu[info] Access destination IP address: XXXX�v�̂悤�ɃA�N�Z�X���IP�A�h���X���o�͂���܂��B

![Capture_connect_ST](/docs/Capture_connect_ST.png)

��ESP8266��11b/g/n�����T�|�[�g���Ă��Ȃ����߁A�ڑ���̃A�N�Z�X�|�C���g��2.4GHz�т̂��̂ɐڑ�����K�v������܂��B

### 6.�N���C�A���g�[���̃u���E�U����A�N�Z�X���IP�A�h���X�ɃA�N�Z�X���܂��B
�u���E�U�̌����t�H�[���̂Ƃ���ɁA�A�N�Z�X���IP�A�h���X"X.X.X.X"����͂���Ή��x�Ǝ��x��\�������ʂ��\�������͂��ł��B

![display_capture](/docs/display_capture.png)

#### ��ʂ̐���:
�㕔�ɂ���w�i�����Ƀ��A���^�C���̉��x�Ǝ��x�l��\������܂��B
�O���t�̂Ƃ���ɂ���܂ł̉��x�Ǝ��x���̗������\������܂��B

interval���W�I�{�^���ł́A�����x���̍X�V���Ԃ�ύX�ł��܂��B(1s,5s,30s,60s,300s�̂�)

Reset graph�{�^�����N���b�N����ƁA�O���t�����Z�b�g����܂��B


# ���C�Z���X
[MIT](/LICENSE)

# �쐬��
[shiguregaki](https://github.com/shiguregaki)
