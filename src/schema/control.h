#pragma once

#include <Arduino.h>
#include <ArduinoJson.h>

#include "data_type.h"
#include "io.h"

template <DataType DT>
class Control : public IO<DT>
{

    public:
        using IO<DT>::IO;
        virtual ~Control() = default;

        virtual void dumpJson(JsonObject obj) const override
        {
            IO<DT>::dumpJsonImpl(obj);
        }
};