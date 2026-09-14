#pragma once

#include <Arduino.h>
#include <ArduinoJson.h>

#include "data_type.h"
#include "io.h"

template <DataType DT>
class Output : public IO<DT>
{

    public:
        using IO<DT>::IO;
        virtual ~Output() = default;

        virtual void dumpJson(JsonObject obj) const override
        {
            IO<DT>::dumpJsonImpl(obj);
        }
};