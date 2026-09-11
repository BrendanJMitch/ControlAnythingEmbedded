#pragma once

#if defined(ARDUINO_ARCH_ESP32)
    #include "ESP32/control_anything_esp32.h"
#else
    #error "No default Network implementation for this platform"
#endif