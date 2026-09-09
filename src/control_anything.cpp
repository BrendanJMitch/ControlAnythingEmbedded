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

void ControlAnything::addIntControl(const Control &control, IntFunc callback)
{
}

void ControlAnything::addBoolControl(const Control &control, BoolFunc callback)
{
}

void ControlAnything::addFloatControl(const Control &control, FloatFunc callback)
{
}

void ControlAnything::addStrControl(const Control &control, StrFunc callback)
{
}

IntFunc ControlAnything::addIntOutput(const Output &output)
{
    return IntFunc();
}

FloatFunc ControlAnything::addFloatOutput(const Output &output)
{
    return FloatFunc();
}

BoolFunc ControlAnything::addBoolOutput(const Output &output)
{
    return BoolFunc();
}

StrFunc ControlAnything::addStrOutput(const Output &output)
{
    return StrFunc();
}
