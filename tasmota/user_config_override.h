#ifndef _USER_CONFIG_OVERRIDE_H_
#define _USER_CONFIG_OVERRIDE_H_

// ESP32-S3 with OPI PSRAM and Webcam support
#define USE_WEBCAM
#define USE_ESP32_S3

// Enable OPI PSRAM for ESP32-S3
#define CONFIG_SPIRAM_MODE_OCT 1

// Webcam settings for OV3660
#define WEBCAM_V2 1

// Optional: Enable additional features
#define USE_UFILESYS
#define USE_SDCARD
#define GUI_TRASH_FILE

#endif
