#include "toggle_widget.h"

ToggleWidget::ToggleWidget(bool defaultVal) : defaultVal(defaultVal)
{
}

std::unique_ptr<Widget> ToggleWidget::clone() const
{
    return std::unique_ptr<ToggleWidget>(new ToggleWidget(*this));
}

const String ToggleWidget::dumpJson(String leadingWhitespace) const
{
    return "";
}