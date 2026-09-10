#pragma once

#include "widget.h"

class NumericOutputWidget : public Widget{
    public:
        NumericOutputWidget(String suffix);
        std::unique_ptr<Widget> clone() const override;
        const String dumpJson(String leadingWhitespace) const override;

    private:
        const String suffix;
};

template<> struct WidgetSupports<NumericOutputWidget, DataType::INT>   : std::true_type {};
template<> struct WidgetSupports<NumericOutputWidget, DataType::FLOAT> : std::true_type {};