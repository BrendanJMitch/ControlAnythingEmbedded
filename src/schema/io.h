#pragma once

#include <memory>
#include <vector>

#include "serializable.h"
#include "widget.h"
#include "data_type.h"

template<DataType DT>
class IO : public Serializable {

    public:
        template<typename WidgetT, size_t N>
        IO(std::array<String, N> topics, const String displayName, const WidgetT &widget)
            : topics(topics.begin(), topics.end()), displayName(displayName), widget(widget.clone()) 
        {
            static_assert(WidgetSupports<WidgetT, DT>::value,
                "Cannot add widget to control with incompatible data type");
            static_assert(WidgetT::arity == N || WidgetT::arity < 0,
                "Incorrect number of topics assigned to this widget");
        }

        const std::vector<String> topics;
        const String displayName;
        const std::unique_ptr<const Widget> widget;

    protected:
        const String dumpJsonImpl(String leadingWhitespace) const{
            return
                leadingWhitespace + "{\r\n" +
                keyValToJson("topics", vectorToJson(topics, leadingWhitespace + TAB), leadingWhitespace + TAB) +
                keyValToJson("displayName", displayName, leadingWhitespace + TAB) +
                keyValToJson("type", DataTypeOf<DT>::value, leadingWhitespace + TAB) + 
                keyValToJson("widget", widget->dumpJson(leadingWhitespace + TAB), leadingWhitespace + TAB) + 
                leadingWhitespace + "}";
        }
};