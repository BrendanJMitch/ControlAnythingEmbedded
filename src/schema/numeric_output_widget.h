#pragma once

#include "widget.h"

class NumericOutputWidget : public Widget
{
    public:
        static constexpr const int arity = 1;

        NumericOutputWidget(String suffix);
        std::unique_ptr<Widget> clone() const override;
        const String dumpJson(const uint8_t indentLevel) const override;

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