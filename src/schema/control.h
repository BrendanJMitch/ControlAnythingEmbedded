#pragma once

#include "io.h"

class Control : public IO {
    public:
        Control(std::vector<String> topics, String displayName, const Widget &widget);
        virtual const String dumpJson(String leadingWhitespace) const;
};