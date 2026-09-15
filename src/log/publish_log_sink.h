#pragma once

#include "log_sink.h"
#include <functional>

class PublishLogSink : public LogSink
{
    public:
        PublishLogSink(std::function<void(const String topic, const String message)> publish);
        virtual void write(const LogLevel level, const String message) const override;

    protected:
        std::function<void(const String topic, const String message)> publish;
        virtual const String levelTopic(const LogLevel level) const;
};
