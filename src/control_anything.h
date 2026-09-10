#pragma once

#include <Arduino.h>

#include "schema/control.h"
#include "schema/output.h"
#include "schema/data_type.h"

typedef void (*IntFunc)(int);
typedef void (*BoolFunc)(bool);
typedef void (*FloatFunc)(float);
typedef void (*StrFunc)(String);

class ControlAnything {

    public:
        ControlAnything();
        static ControlAnything &get();

        virtual void setNetworkSSID(String ssid);
        virtual void setNetworkPassword(String password);
        virtual void setDeviceName(String deviceName);
        virtual void setProjectId(String projectName);


        virtual void initialize(bool host) = 0;

        virtual void addControl(const Control<DataType::INT>& control, IntFunc callback);
        virtual void addControl(const Control<DataType::BOOL>& control, BoolFunc callback);
        virtual void addControl(const Control<DataType::FLOAT>& control, FloatFunc callback);
        virtual void addControl(const Control<DataType::STRING>& control, StrFunc callback);

        virtual IntFunc addOutput(const Output<DataType::INT>& output);
        virtual BoolFunc addOutput(const Output<DataType::BOOL>& output);
        virtual FloatFunc addOutput(const Output<DataType::FLOAT>& output);
        virtual StrFunc addOutput(const Output<DataType::STRING>& output);

        virtual void start() = 0;

    protected:
        String ssid;
        String password;
        String deviceName;
        String projectName;
        String controls;
        String outputs;

        virtual void subscribe(String topic, StrFunc callback) = 0;
};
