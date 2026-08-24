#include "ControlAnythingESP32.h"

ControlAnythingESP32::ControlAnythingESP32(uint8_t pin) : _pin(pin) {}

void ControlAnythingESP32::begin() {
    pinMode(_pin, OUTPUT);
}

void ControlAnythingESP32::update() {
    // TODO: replace with real behavior
    digitalWrite(_pin, !digitalRead(_pin));
}
