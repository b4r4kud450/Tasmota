#!/usr/bin/env python3
"""
Патч camera_pins.h для Freenove ESP32-S3 WROOM + OV3660
Використовується у GitHub Actions workflow
"""
import sys
import os

PATCH = """
#elif defined(CAMERA_MODEL_FREENOVE_ESP32S3)
// Freenove ESP32-S3 WROOM - OV3660 pinout
// Source: docs.freenove.com/projects/fnk0086
#define PWDN_GPIO_NUM  -1
#define RESET_GPIO_NUM -1
#define XCLK_GPIO_NUM  15
#define SIOD_GPIO_NUM  4
#define SIOC_GPIO_NUM  5

#define Y2_GPIO_NUM    11
#define Y3_GPIO_NUM    9
#define Y4_GPIO_NUM    8
#define Y5_GPIO_NUM    10
#define Y6_GPIO_NUM    12
#define Y7_GPIO_NUM    18
#define Y8_GPIO_NUM    17
#define Y9_GPIO_NUM    16

#define VSYNC_GPIO_NUM 6
#define HREF_GPIO_NUM  7
#define PCLK_GPIO_NUM  13

"""

def patch(filepath):
    if not os.path.exists(filepath):
        print(f"ERROR: {filepath} not found!")
        sys.exit(1)

    with open(filepath, 'r') as f:
        content = f.read()

    if 'CAMERA_MODEL_FREENOVE_ESP32S3' in content:
        print("Patch already applied, skipping.")
        return

    # Вставляємо перед останнім #else
    marker = '\n#else\n'
    idx = content.rfind(marker)
    if idx == -1:
        print("ERROR: could not find final #else in camera_pins.h!")
        sys.exit(1)

    new_content = content[:idx] + PATCH + content[idx:]
    with open(filepath, 'w') as f:
        f.write(new_content)
    print(f"Patch applied to {filepath}")

if __name__ == '__main__':
    if len(sys.argv) < 2:
        print("Usage: patch_camera_pins.py <path/to/camera_pins.h>")
        sys.exit(1)
    patch(sys.argv[1])
