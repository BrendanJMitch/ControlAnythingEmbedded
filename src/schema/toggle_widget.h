#pragma once

#include "data_type.h"
#include "widget.h"

class ToggleWidget : public Widget
{
    public:
        static constexpr const int arity = 1;

        ToggleWidget(bool defaultVal);
        std::unique_ptr<Widget> clone() const override;
        const String dumpJson(const uint8_t indentLevel) const override;

    private:
        const bool defaultVal;
};

template <>
struct WidgetSupports<ToggleWidget, DataType::BOOL> : std::true_type
{
};
