#include "publish_log_sink.h"

PublishLogSink::PublishLogSink(
    std::function<void(const String topic, const String message)> publish)
    : publish(publish)
{
}

void PublishLogSink::write(const LogLevel level, const String message) const
{
    publish(levelTopic(level), message);
}

const String PublishLogSink::levelTopic(const LogLevel level) const
{
    const String levelStr = level.label;
    return "log/" + levelStr;
}
