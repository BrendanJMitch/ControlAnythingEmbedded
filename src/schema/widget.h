#pragma once

#include "data_type.h"
#include "serializable.h"
#include <Arduino.h>
#include <memory>
#include <type_traits>

class Widget : public Serializable
{
    public:
        virtual ~Widget() = default;
        virtual std::unique_ptr<Widget> clone() const = 0;
        virtual String dumpJson(uint8_t indentLevel) const override = 0;
};

template <typename WidgetT, DataType DT>
struct WidgetSupports : std::false_type
{
};
