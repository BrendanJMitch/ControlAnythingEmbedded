#pragma once

#include "io.h"
#include "data_type.h"

template<DataType DT>
class Output : public IO<DT> {

    public:
        template<typename WidgetT, size_t N>
        Output(std::array<String, N> topics, String displayName, const WidgetT &widget)
            : IO<DT>(topics, displayName, widget)
        {
        }
        
        virtual const String dumpJson(const uint8_t indentLevel) const override
        {
            return IO<DT>::dumpJsonImpl(indentLevel);
        }
};