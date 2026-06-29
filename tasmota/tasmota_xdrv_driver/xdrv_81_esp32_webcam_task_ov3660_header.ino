// xdrv_81_esp32_webcam_task.ino - MODIFIED FOR OV3660
// =============================================================================
// ПРИНЦИП РОБОТИ (як ESPHome/Arduino):
// 1. esp_camera_init() ініціалізує драйвер Espressif
// 2. esp_camera_sensor_get() повертає sensor_t* — generic інтерфейс
// 3. Всі налаштування через sensor_t API (set_framesize, set_quality, etc.)
// 4. НІЯКИХ прямих записів в регістри сенсора!
// 5. OV3660 підтримується нативно в esp32-camera driver
// =============================================================================

#ifdef ESP32
#ifdef USE_WEBCAM
#ifdef USE_WEBCAM_V2

#undef WEBCAM_DEV_DEBUG

#define XDRV_81 81

#include "cam_hal.h"
#include "esp_camera.h"
#include "sensor.h"
#include "fb_gfx.h"
#include "jpeg_decoder.h"

// =============================================================================
// OV3660 FIX: Видалено #include <OV2640.h>
// Причина: OV2640.h — це заголовок з бібліотеки esp32-camera, який містить
// специфічні структури для OV2640. Для OV3660 він не потрібен.
// Замість нього використовуємо generic API esp_camera.h
// =============================================================================

#ifdef ENABLE_RTSPSERVER
#include <WiFiServer.h>
#include <WiFiClient.h>
#include <CRtspSession.h>
#include <CStreamer.h>
#include <JPEGSamples.h>

#ifndef RTSP_FRAME_TIME
#define RTSP_FRAME_TIME 100
#endif // RTSP_FRAME_TIME

// =============================================================================
// OV3660 FIX: Клас переіменовано з localOV2640Streamer → localCameraStreamer
// Причина: Клас не залежить від конкретного сенсора, він працює з JPEG frame buffer
// =============================================================================
class localCameraStreamer : public CStreamer {
    BufPtr f_ptr;
    int f_len;
public:
    localCameraStreamer(SOCKET aClient, int width, int height);
    void setframe(BufPtr ptr, int len);
    void clearframe();
    virtual void streamImage(uint32_t curMsec);
};

localCameraStreamer::localCameraStreamer(SOCKET aClient, int width, int height) 
    : CStreamer(aClient, width, height) {
    clearframe();
#ifdef WEBCAM_DEV_DEBUG
    AddLog(LOG_LEVEL_DEBUG,PSTR("CAM:RTSP w%d h%d"), width, height);
#endif
}

void localCameraStreamer::setframe(BufPtr ptr, int len) {
    f_ptr = ptr;
    f_len = len;
}

void localCameraStreamer::clearframe() {
    f_ptr = nullptr;
    f_len = 0;
}

void localCameraStreamer::streamImage(uint32_t curMsec){
    if (!f_ptr) return;
    streamFrame(f_ptr, f_len, curMsec);
}

typedef struct tag_wc_rtspclient {
    localCameraStreamer * volatile camStreamer;  // OV3660 FIX: renamed
    CRtspSession * volatile rtsp_session;
    WiFiClient rtsp_client;
    tag_wc_rtspclient * volatile p_next;
} wc_rtspclient;
#endif //ENABLE_RTSPSERVER
