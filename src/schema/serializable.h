#pragma once

#include <Arduino.h>
#include <ArduinoJson.h>
#include <vector>

class Serializable
{

    public:
        virtual ~Serializable() = default;
        virtual void dumpJson(JsonObject obj) const = 0;
};
