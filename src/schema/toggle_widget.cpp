#include "toggle_widget.h"

#include <Arduino.h>
#include <memory>

ToggleWidget::ToggleWidget(bool defaultVal) : defaultVal(defaultVal) {}

std::unique_ptr<Widget> ToggleWidget::clone() const
{
    return std::unique_ptr<ToggleWidget>(new ToggleWidget(*this));
}

void ToggleWidget::dumpJson(JsonObject obj) const
{
    obj["type"] = "toggle";
    obj["default_value"] = defaultVal;
}
