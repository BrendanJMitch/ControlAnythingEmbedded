#pragma once

#include <Arduino.h>
#include <functional>

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

        virtual void start() = 0;

    protected:
        String ssid;
        String password;
        String deviceName;
        String projectId;
        String controlsJson;
        String outputsJson;

        virtual void subscribe(String topic, std::function<void(String)>) = 0;
};
