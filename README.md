AM2320-WebGraph

---
English
---
I created a web graph that shows the value of the AM2320 sensor in arudino wifi module(ESP8266).

---
Japanese
---
���̃R�[�h��arudino wifi���W���[����ESP8266��AM2320��Web�O���t��������̂ł��B
AM2320�Z���T�[���h���C���[�ŉ��߂Ă���A���ꂪ���A���^�C���ɕ\������Ă��܂��B

![demo](https://github.com/shiguregaki/AM2320-WebGraph/blob/master/docs/display_AM2320_sensor.gif)

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

![connection_diagram](https://github.com/shiguregaki/AM2320-WebGraph/blob/master/docs/connection_diagram.jpg)

| ���C���̐F | ESP8266�[�q | AM2320�[�q |
|:---|:---|:---|
|�� |3V3 |VDD |
|�� |GPIO4 |SDA |
|�� |GND |GND |
|�� |GPIO5 |SCL |

AM2320�̎d�l��
[Digital Temperature and Humidity Sensor AM2320 Product Manual](https://github.com/shiguregaki/AM2320-WebGraph/blob/master/docs/AM2320.pdf)
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

��Wire.h���C�u�������g���΁AESP8266�̔C�ӂ�GPIO�s����I2C�ŗ��p�ł���悤�ł��B
�������A�����̊��ł͂��܂������܂���ł����B
���̂��߁ASDA_PIN��SCL_PIN��ESP8266�̃f�t�H���gI2C�s���ɂ��邱�Ƃ������߂��܂��B

����AM2320�Z���T�[�̓ǂݎ��Ԋu�̓N���C�A���g�[�����ŌŒ��5�p�^�[�������ݒ�ł��Ȃ��悤�ɂ��Ă��܂��B
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

![Capture_connect_AP](https://github.com/shiguregaki/AM2320-WebGraph/blob/master/docs/Capture_connect_AP.png)

�������A�R�[�h��ssid��password��ς��Ă�����A���̒l�ɕς���Ă��܂��B

#### ST-Mode�̏ꍇ:
�����ŃA�N�Z�X�|�C���g�ɐڑ����܂��B
�V���A�����j�^�ł͐ڑ�����������΁A�ȉ��̂悤�Ɂu[info] Access destination IP address: XXXX�v�̂悤�ɃA�N�Z�X���IP�A�h���X���o�͂���܂��B

![Capture_connect_ST](https://github.com/shiguregaki/AM2320-WebGraph/blob/master/docs/Capture_connect_ST.png)

��ESP8266��11b/g/n�����T�|�[�g���Ă��Ȃ����߁A�ڑ���̃A�N�Z�X�|�C���g��2.4GHz�т̂��̂ɐڑ�����K�v������܂��B

### 6.�N���C�A���g�[���̃u���E�U����A�N�Z�X���IP�A�h���X�ɃA�N�Z�X���܂��B
�u���E�U�̌����t�H�[���̂Ƃ���ɁA�A�N�Z�X���IP�A�h���X"X.X.X.X"����͂���Ή��x�Ǝ��x��\�������ʂ��\�������͂��ł��B

![display_capture](https://github.com/shiguregaki/AM2320-WebGraph/blob/master/docs/display_capture.png)

�㕔�ɂ���w�i�����Ƀ��A���^�C���̉��x�Ǝ��x�l��\������܂��B
�O���t�̂Ƃ���ɂ���܂ł̉��x�Ǝ��x���̗������\������܂��B

interval���W�I�{�^���ł́A�����x���̍X�V���Ԃ�ύX�ł��܂��B(1s,5s,30s,60s,300s�̂�)

Reset graph�{�^�����N���b�N����ƁA�O���t�����Z�b�g����܂��B


# ���C�Z���X
[MIT](https://github.com/shiguregaki/sample/blob/master/03_ESP8266_control_LED_by_websocket/LICENSE)

# �쐬��
[shiguregaki](https://github.com/shiguregaki)
