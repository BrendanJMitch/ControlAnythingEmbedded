#pragma once

#include "io.h"
#include "data_type.h"

template<DataType DT>
class Control : public IO<DT> {

    public:
        template<typename WidgetT>
        Control(std::vector<String> topics, String displayName, const WidgetT& widget)
            : IO<DT>(topics, displayName, widget)
        {
        }
        
        virtual const String dumpJson(String leadingWhitespace) const 
        {
            return IO<DT>::dumpJsonImpl(leadingWhitespace);
        }
};