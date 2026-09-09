#pragma once

#include <Arduino.h>

#include "schema/control.h"
#include "schema/output.h"

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

        virtual void addIntControl(const Control& control, IntFunc callback);
        virtual void addBoolControl(const Control& control, BoolFunc callback);
        virtual void addFloatControl(const Control& control, FloatFunc callback);
        virtual void addStrControl(const Control& control, StrFunc callback);


        virtual IntFunc addIntOutput(const Output& output);
        virtual FloatFunc addFloatOutput(const Output& output);
        virtual BoolFunc addBoolOutput(const Output& output);
        virtual StrFunc addStrOutput(const Output& output);

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
