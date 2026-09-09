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