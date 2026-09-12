#pragma once

#include <Arduino.h>

#include "data_type.h"
#include "io.h"

template <DataType DT>
class Output : public IO<DT>
{

    public:
        using IO<DT>::IO;
        virtual ~Output() = default;

        virtual String dumpJson(const uint8_t indentLevel) const override
        {
            return IO<DT>::dumpJsonImpl(indentLevel);
        }
};