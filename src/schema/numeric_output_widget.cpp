#include "numeric_output_widget.h"

#include <Arduino.h>
#include <memory>

NumericOutputWidget::NumericOutputWidget(String suffix) : suffix(suffix) {}

std::unique_ptr<Widget> NumericOutputWidget::clone() const
{
    return std::unique_ptr<NumericOutputWidget>(new NumericOutputWidget(*this));
}

void NumericOutputWidget::dumpJson(JsonObject obj) const
{
    obj["type"] = "numeric_output";
    obj["suffix"] = suffix;
}
