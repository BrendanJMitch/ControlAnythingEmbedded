#include "log_sink.h"

class PrintLogSink : public LogSink
{
    public:
        PrintLogSink(Print& out);
        virtual void write(const LogLevel level, const String message) const override;

    protected:
        Print& out;
        const String levelPrefix(const LogLevel level) const;
};