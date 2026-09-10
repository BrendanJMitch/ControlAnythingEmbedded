#pragma once

#include "widget.h"
#include "data_type.h"

class ToggleWidget : public Widget{
    public:
        ToggleWidget(bool defaultVal);
        std::unique_ptr<Widget> clone() const override;
        const String dumpJson(String leadingWhitespace) const override;

    private:
        const bool defaultVal;

};


template<> struct WidgetSupports<ToggleWidget, DataType::BOOL> : std::true_type {};

