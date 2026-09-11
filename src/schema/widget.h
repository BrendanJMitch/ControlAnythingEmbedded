#pragma once

#include "data_type.h"
#include "serializable.h"
#include <memory>

class Widget : public Serializable
{

    public:
        virtual std::unique_ptr<Widget> clone() const = 0;
        virtual const String dumpJson(uint8_t indentLevel) const override = 0;
};

template <typename WidgetT, DataType DT>
struct WidgetSupports : std::false_type
{
};
