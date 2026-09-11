#pragma once

#include <memory>
#include "serializable.h"
#include "data_type.h"

class Widget : public Serializable {

    public:
        virtual std::unique_ptr<Widget> clone() const = 0;
        virtual const String dumpJson(String leadingWhitespace) const = 0;
};

template<typename WidgetT, DataType DT>
struct WidgetSupports : std::false_type {};
