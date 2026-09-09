#pragma once

#include <memory>
#include "serializable.h"

class Widget : public Serializable {

    public:
        virtual std::unique_ptr<Widget> clone() const = 0;
        virtual const String dumpJson(String leadingWhitespace) const = 0;
};