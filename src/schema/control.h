#pragma once

#include <Arduino.h>

#include "data_type.h"
#include "io.h"

template <DataType DT>
class Control : public IO<DT>
{

    public:
        using IO<DT>::IO;
        virtual ~Control() = default;

        virtual String dumpJson(const uint8_t indentLevel) const override
        {
            return IO<DT>::dumpJsonImpl(indentLevel);
        }
};