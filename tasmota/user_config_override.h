/*
  user_config_override.h - Tasmota для Freenove ESP32-S3 WROOM + OV3660
*/

#ifndef _USER_CONFIG_OVERRIDE_H_
#define _USER_CONFIG_OVERRIDE_H_

#define USE_WEBCAM
#define USE_ESP32_CAM

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

#define WIFI_DEFAULT_HOSTNAME "freenove-cam"

#endif
