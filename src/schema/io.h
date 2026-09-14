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
        void dumpJsonImpl(JsonObject json) const
        {
            JsonArray topicsJson = json["topics"].to<JsonArray>();
            for (String topic : topics)
            {
                topicsJson.add(topic);
            }
            json["displayName"] = displayName;
            json["type"] = DataTypeOf<DT>::value;
            JsonObject widgetJson = json["widget"].to<JsonObject>();
            widget->dumpJson(widgetJson);
        }
};