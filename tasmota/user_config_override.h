/*
  user_config_override.h - Tasmota для Freenove ESP32-S3 WROOM + OV3660
  Скопіюйте в папку tasmota/ як user_config_override.h
*/

#ifndef _USER_CONFIG_OVERRIDE_H_
#define _USER_CONFIG_OVERRIDE_H_

// -- Webcam налаштування --------------------------
#undef  USE_WEBCAM
#define USE_WEBCAM                         // Увімкнути підтримку вебкамери
#define USE_WEBCAM_V2                      // Використати новий драйвер V2 (кращий для ESP32-S3)

// -- Ініціалізація камери при старті --------------
// Команда яка виконається при завантаженні:
// WcInit - ініціалізує камеру
// WcResolution 8 - встановлює VGA (640x480)

// -- WiFi (за бажанням, можна налаштувати через вебінтерфейс)
//#undef  STA_SSID1
//#define STA_SSID1     "your_wifi_name"
//#undef  STA_PASS1
//#define STA_PASS1     "your_wifi_password"

// -- Hostname
#undef  WIFI_HOSTNAME
#define WIFI_HOSTNAME "freenove-cam"

// -- MQTT (за бажанням)
//#undef  MQTT_HOST
//#define MQTT_HOST     "192.168.1.100"

#endif  // _USER_CONFIG_OVERRIDE_H_
