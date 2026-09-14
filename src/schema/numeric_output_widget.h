#pragma once

#include <Arduino.h>
#include <ArduinoJson.h>
#include <memory>
#include <type_traits>

#include "data_type.h"
#include "widget.h"

class NumericOutputWidget : public Widget
{
    public:
        static constexpr const int arity = 1;

        NumericOutputWidget(String suffix);
        std::unique_ptr<Widget> clone() const override;
        virtual void dumpJson(JsonObject obj) const override;

    private:
        const String suffix;
};

template <>
struct WidgetSupports<NumericOutputWidget, DataType::INT> : std::true_type
{
};
template <>
struct WidgetSupports<NumericOutputWidget, DataType::FLOAT> : std::true_type
{
};