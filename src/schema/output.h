#pragma once

#include "io.h"

class Output : public IO {
    public:
        Output(std::vector<String> topics, String displayName, const Widget &widget);
        virtual const String dumpJson(String leadingWhitespace) const;
};