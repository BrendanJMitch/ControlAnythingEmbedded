#include "log_level.h"

LogLevel::LogLevel(const char* label, const uint8_t value) : label(label), value(value) {}

LogLevel::operator const uint8_t() const
{
    return value;
}

const LogLevel LogLevel::DEBUG("debug", 10);
const LogLevel LogLevel::INFO("info", 20);
const LogLevel LogLevel::WARNING("warning", 30);
const LogLevel LogLevel::ERROR("error", 40);
const LogLevel LogLevel::CRITICAL("critical", 50);