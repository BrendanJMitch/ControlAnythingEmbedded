#include "print_log_sink.h"

PrintLogSink::PrintLogSink(Print& out) : out(out) {}

void PrintLogSink::write(const LogLevel level, const String message) const
{
    out.println(levelPrefix(level) + message);
}

const String PrintLogSink::levelPrefix(const LogLevel level) const
{
    String levelStr = level.label;
    levelStr.toUpperCase();
    return levelStr + ": ";
}
