#pragma once

#include "Arduino.h"
#include "log_level.h"

class LogSink
{
    public:
        virtual void write(const LogLevel level, const String message) const = 0;
};