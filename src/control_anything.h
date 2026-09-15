#pragma once

#include <Arduino.h>
#include <ArduinoJson.h>
#include <functional>
#include <vector>

#include "log/log_level.h"
#include "log/log_sink.h"
#include "schema/control.h"
#include "schema/data_type.h"
#include "schema/output.h"

typedef std::function<void(const uint8_t, const int)> IntCallback;
typedef std::function<void(const uint8_t, const bool)> BoolCallback;
typedef std::function<void(const uint8_t, const float)> FloatCallback;
typedef std::function<void(const uint8_t, const String)> StringCallback;

class ControlAnything
{

    public:
        ControlAnything();
        virtual ~ControlAnything() = default;
        static ControlAnything& get();

        void setNetworkSSID(String ssid);
        void setNetworkPassword(String password);
        void setDeviceName(String deviceName);
        void setProjectId(String projectId);

        virtual void initialize(bool host) = 0;

        void addControl(const Control<DataType::INT>& control, IntCallback callback);
        void addControl(const Control<DataType::BOOL>& control, BoolCallback callback);
        void addControl(const Control<DataType::FLOAT>& control, FloatCallback callback);
        void addControl(const Control<DataType::STRING>& control, StringCallback callback);

        IntCallback addOutput(const Output<DataType::INT>& output);
        BoolCallback addOutput(const Output<DataType::BOOL>& output);
        FloatCallback addOutput(const Output<DataType::FLOAT>& output);
        StringCallback addOutput(const Output<DataType::STRING>& output);

        void addLogSink(const LogSink& sink);
        void addLogSink(Print& sink);

        void log(const LogLevel level, const String message) const;
        void log(const uint8_t level, const String message) const;
        void debug(const String message) const;
        void info(const String message) const;
        void warning(const String message) const;
        void error(const String message) const;
        void critical(const String message) const;

        virtual void start() = 0;

    protected:
        uint8_t logLevel;
        JsonDocument json;
        String ssid;
        String password;
        std::vector<const LogSink*> logSinks;

        virtual void subscribe(const String topic, std::function<void(String)>) = 0;
        virtual void publish(const String topic, const String value) const = 0;
};
