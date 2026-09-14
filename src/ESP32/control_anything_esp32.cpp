#include "control_anything_esp32.h"
#include <esp_system.h>

#include <Arduino.h>
#include <functional>

ControlAnythingEsp32::ControlAnythingEsp32() : ControlAnything()
{
    uint64_t mac = ESP.getEfuseMac();
    char id[13];
    snprintf(id, sizeof(id), "%012llX", mac);

    json["device_id"] = id;
}

void ControlAnythingEsp32::initialize(bool host) {}

void ControlAnythingEsp32::start() {}

void ControlAnythingEsp32::subscribe(String topic, std::function<void(String)>) {}

void ControlAnythingEsp32::publish(String topic, String value) const {}
