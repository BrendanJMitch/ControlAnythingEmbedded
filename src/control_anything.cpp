#include "control_anything.h"

#include <Arduino.h>

#include "platform_config.h"
#include "schema/control.h"
#include "schema/data_type.h"
#include "schema/output.h"

ControlAnything::ControlAnything() {}

ControlAnything& ControlAnything::get()
{
    static ControlAnythingImpl instance;
    return instance;
}

void ControlAnything::setNetworkSSID(String ssid)
{
    this->ssid = ssid;
}

void ControlAnything::setNetworkPassword(String password)
{
    this->password = password;
}

void ControlAnything::setDeviceName(String deviceName)
{
    this->deviceName = deviceName;
}

void ControlAnything::setProjectId(String projectId)
{
    this->projectId = projectId;
}

void ControlAnything::addControl(const Control<DataType::INT>& control, IntCallback callback)
{
    controlsJson += ",\r\n" + control.dumpJson(2);
    for (uint8_t i = 0; i < control.topics.size(); i++)
    {
        subscribe(control.topics[i], [i, callback](String value) { callback(i, value.toInt()); });
    }
}

void ControlAnything::addControl(const Control<DataType::BOOL>& control, BoolCallback callback) {}

void ControlAnything::addControl(const Control<DataType::FLOAT>& control, FloatCallback callback) {}

void ControlAnything::addControl(const Control<DataType::STRING>& control, StringCallback callback)
{
}

IntCallback ControlAnything::addOutput(const Output<DataType::INT>& output)
{
    return IntCallback();
}

BoolCallback ControlAnything::addOutput(const Output<DataType::BOOL>& output)
{
    return BoolCallback();
}

FloatCallback ControlAnything::addOutput(const Output<DataType::FLOAT>& output)
{
    return FloatCallback();
}

StringCallback ControlAnything::addOutput(const Output<DataType::STRING>& output)
{
    return StringCallback();
}
