#pragma once

#include <Arduino.h>
#include <array>
#include <memory>
#include <vector>

#include "data_type.h"
#include "serializable.h"
#include "widget.h"

template <DataType DT>
class IO : public Serializable
{

    public:
        template <typename WidgetT, size_t N>
        IO(const std::array<String, N>& topics, const String& displayName, const WidgetT& widget)
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
        String dumpJsonImpl(const uint8_t indentLevel) const
        {
            String indent = getIndent(indentLevel);
            return indent + "{\r\n" +
                   keyValToJson(indentLevel + 1, "topics", vectorToJson(indentLevel + 1, topics)) +
                   keyValToJson(indentLevel + 1, "displayName", displayName) +
                   keyValToJson(indentLevel + 1, "type", DataTypeOf<DT>::value) +
                   keyValToJson(indentLevel + 1, "widget", widget->dumpJson(indentLevel + 1)) +
                   indent + "}";
        }
};