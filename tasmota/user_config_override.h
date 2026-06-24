#ifndef _USER_CONFIG_OVERRIDE_H_
#define _USER_CONFIG_OVERRIDE_H_

// ============================================
// ESP32-S3 WROOM (Freenove) + OV3660 Webcam
// ============================================

// Вимкнути стандартні функції для економії місця
#undef USE_DOMOTICZ
#undef USE_HOME_ASSISTANT
#undef USE_KNX
#undef USE_IR_REMOTE
#undef USE_IR_RECEIVE
#undef USE_RF_BRIDGE
#undef USE_ZIGBEE
#undef USE_BLE_ESP32
#undef USE_MI_ESP32

// Увімкнути вебкамеру (ОБОВ'ЯЗКОВО)
#define USE_WEBCAM

// Налаштування камери OV3660
#define WEBCAM_V2
#define USE_WEBCAM_FAST_XCLK

// Увімкнути PSRAM для буфера камери
#define USE_PSRAM

// Увімкнути файлову систему для збереження знімків
#define USE_UFILESYS
#define GUI_TRASH_FILE

// Увімкнути HTTP сервер для стріму
#define USE_WEBSERVER
#define WEBSERVER_ADVERTISE

// Увімкнути MJPEG стрім
#define USE_WEBCAM_MOTION

// Налаштування пінів для Freenove ESP32-S3 (типові)
// Якщо не працює — перевірте піни у документації плати
#define WEBCAM_PWDN     -1
#define WEBCAM_RESET    -1
#define WEBCAM_XCLK     15
#define WEBCAM_SIOD     4   // SDA
#define WEBCAM_SIOC     5   // SCL
#define WEBCAM_D0       11
#define WEBCAM_D1       9
#define WEBCAM_D2       8
#define WEBCAM_D3       10
#define WEBCAM_D4       12
#define WEBCAM_D5       18
#define WEBCAM_D6       17
#define WEBCAM_D7       16
#define WEBCAM_VSYNC    6
#define WEBCAM_HREF     7
#define WEBCAM_PCLK     13

#endif
