#include "control_anything.h"
#include "platform_config.h"
#include "control_anything.h"
#include "schema/control.h"

ControlAnything::ControlAnything()
{
}

ControlAnything &ControlAnything::get()
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

void ControlAnything::setProjectId(String projectName)
{
    this->projectName = projectName;
}

void ControlAnything::addControl(const Control<DataType::INT> &control, IntFunc callback)
{
}

void ControlAnything::addControl(const Control<DataType::BOOL> &control, BoolFunc callback)
{
}

void ControlAnything::addControl(const Control<DataType::FLOAT> &control, FloatFunc callback)
{
}

void ControlAnything::addControl(const Control<DataType::STRING> &control, StrFunc callback)
{
}

IntFunc ControlAnything::addOutput(const Output<DataType::INT> &output)
{
    return IntFunc();
}

BoolFunc ControlAnything::addOutput(const Output<DataType::BOOL> &output)
{
    return BoolFunc();
}

FloatFunc ControlAnything::addOutput(const Output<DataType::FLOAT> &output)
{
    return FloatFunc();
}

StrFunc ControlAnything::addOutput(const Output<DataType::STRING> &output)
{
    return StrFunc();
}
