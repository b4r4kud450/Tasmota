/*
  user_config_override.h - Freenove ESP32-S3 WROOM N16R8 + OV3660
  Скопіюйте в папку tasmota/
*/

#ifndef _USER_CONFIG_OVERRIDE_H_
#define _USER_CONFIG_OVERRIDE_H_

// ============================================
// Freenove ESP32-S3 WROOM піни для OV3660
// ============================================
// КРИТИЧНО: Ці дефайни використовуються як fallback,
// якщо піни не налаштовані через Template/GPIO
#define PWDN_GPIO_NUM     -1
#define RESET_GPIO_NUM    -1
#define XCLK_GPIO_NUM     15
#define SIOD_GPIO_NUM     17
#define SIOC_GPIO_NUM     18
#define Y9_GPIO_NUM       39
#define Y8_GPIO_NUM       40
#define Y7_GPIO_NUM       41
#define Y6_GPIO_NUM       42
#define Y5_GPIO_NUM       21
#define Y4_GPIO_NUM       48
#define Y3_GPIO_NUM       47
#define Y2_GPIO_NUM       14
#define VSYNC_GPIO_NUM    38
#define HREF_GPIO_NUM     45
#define PCLK_GPIO_NUM     16

// ============================================
// Hostname
// ============================================
#define WIFI_DEFAULT_HOSTNAME "freenove-cam"

// ============================================
// Додаткові налаштування
// ============================================
// Збільшити WiFi таймаут для стабільності
#define WIFI_CONFIG_TOOL       WIFI_MANAGER

#endif
