#pragma once

#include <Arduino.h>

class ControlAnythingESP32 {
public:
    explicit ControlAnythingESP32(uint8_t pin);

    void begin();
    void update();

private:
    uint8_t _pin;
};
