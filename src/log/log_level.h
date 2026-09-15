#pragma once
#include <Arduino.h>

class LogLevel
{

    public:
        static const LogLevel DEBUG;
        static const LogLevel INFO;
        static const LogLevel WARNING;
        static const LogLevel ERROR;
        static const LogLevel CRITICAL;

        const char* label;
        const uint8_t value;

        operator const uint8_t() const;

    private:
        LogLevel(const char* label, const uint8_t value);
};