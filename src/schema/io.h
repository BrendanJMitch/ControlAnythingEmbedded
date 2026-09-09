#pragma once

#include <memory>
#include <vector>

#include "serializable.h"
#include "widget.h"

class IO : public Serializable {

    public:
        IO(std::vector<String> topics, const String displayName, const Widget &widget);

        const std::vector<String> topics;
        const String displayName;
        const std::unique_ptr<const Widget> widget;

    protected:
        const String dumpJsonImpl(String leadingWhitespace) const;
};