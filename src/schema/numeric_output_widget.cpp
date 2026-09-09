#include "numeric_output_widget.h"

#include <memory>


NumericOutputWidget::NumericOutputWidget(String suffix) : suffix(suffix)
{
}

std::unique_ptr<Widget> NumericOutputWidget::clone() const
{
    return std::unique_ptr<NumericOutputWidget>(new NumericOutputWidget(*this));
}

const String NumericOutputWidget::dumpJson(String leadingWhitespace) const
{
    return String();
}
