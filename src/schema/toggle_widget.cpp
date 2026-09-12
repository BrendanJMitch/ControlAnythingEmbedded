#include "toggle_widget.h"

#include <Arduino.h>
#include <memory>

ToggleWidget::ToggleWidget(bool defaultVal) : defaultVal(defaultVal) {}

std::unique_ptr<Widget> ToggleWidget::clone() const
{
    return std::unique_ptr<ToggleWidget>(new ToggleWidget(*this));
}

String ToggleWidget::dumpJson(const uint8_t indentLevel) const
{
    return String();
}