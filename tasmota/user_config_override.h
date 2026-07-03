/*
  user_config_override.h - Freenove ESP32-S3 WROOM N16R8 + OV3660
  Скопіюйте в папку tasmota/
*/

#ifndef _USER_CONFIG_OVERRIDE_H_
#define _USER_CONFIG_OVERRIDE_H_

// ============================================
// Freenove ESP32-S3 WROOM піни для OV3660
// ============================================
#define PWDN_GPIO_NUM     -1
#define RESET_GPIO_NUM    -1
#define XCLK_GPIO_NUM     15
#define SIOD_GPIO_NUM     4
#define SIOC_GPIO_NUM     5
#define Y9_GPIO_NUM       16
#define Y8_GPIO_NUM       17
#define Y7_GPIO_NUM       18
#define Y6_GPIO_NUM       12
#define Y5_GPIO_NUM       10
#define Y4_GPIO_NUM       8
#define Y3_GPIO_NUM       9
#define Y2_GPIO_NUM       11
#define VSYNC_GPIO_NUM    6
#define HREF_GPIO_NUM     7
#define PCLK_GPIO_NUM     13

// ============================================
// Hostname
// ============================================
#define WIFI_DEFAULT_HOSTNAME "freenove-cam"

// ============================================
// WiFi Config Tool
// ============================================
#undef WIFI_CONFIG_TOOL
#define WIFI_CONFIG_TOOL WIFI_MANAGER
#define WIFI_AP_PASSPHRASE "tasmota123"

// ============================================
// Вимкнути LVGL/Display для стабільності камери
// ============================================
#undef USE_LVGL
#undef USE_DISPLAY
#undef USE_HASPMOTA

#endif
