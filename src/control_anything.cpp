#include "control_anything.h"

#include <Arduino.h>

#include "platform_config.h"
#include "schema/control.h"
#include "schema/data_type.h"
#include "schema/output.h"

ControlAnything::ControlAnything()
{
    json["controls"].to<JsonArray>();
    json["outputs"].to<JsonArray>();
}

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
    json["device_name"] = deviceName;
}

void ControlAnything::setProjectId(String projectId)
{
    json["project_id"] = projectId;
}

void ControlAnything::addControl(const Control<DataType::INT>& control, IntCallback callback)
{
    control.dumpJson(json["controls"].as<JsonArray>().add<JsonObject>());
    for (uint8_t i = 0; i < control.topics.size(); i++)
    {
        subscribe(control.topics[i], [i, callback](String value) { callback(i, value.toInt()); });
    }
}

void ControlAnything::addControl(const Control<DataType::BOOL>& control, BoolCallback callback)
{
    control.dumpJson(json["controls"].as<JsonArray>().add<JsonObject>());
    for (uint8_t i = 0; i < control.topics.size(); i++)
    {
        subscribe(control.topics[i],
                  [i, callback](String value)
                  {
                      if (value.equalsIgnoreCase("true"))
                      {
                          callback(i, true);
                      }
                      else
                      {
                          callback(i, false);
                      }
                  });
    }
}

void ControlAnything::addControl(const Control<DataType::FLOAT>& control, FloatCallback callback)
{
    control.dumpJson(json["controls"].as<JsonArray>().add<JsonObject>());
    for (uint8_t i = 0; i < control.topics.size(); i++)
    {
        subscribe(control.topics[i], [i, callback](String value) { callback(i, value.toFloat()); });
    }
}

void ControlAnything::addControl(const Control<DataType::STRING>& control, StringCallback callback)
{
    control.dumpJson(json["controls"].as<JsonArray>().add<JsonObject>());
    for (uint8_t i = 0; i < control.topics.size(); i++)
    {
        subscribe(control.topics[i], [i, callback](String value) { callback(i, value); });
    }
}

IntCallback ControlAnything::addOutput(const Output<DataType::INT>& output)
{
    output.dumpJson(json["outputs"].as<JsonArray>().add<JsonObject>());
    std::vector<String> topics = output.topics;
    return [this, topics](uint8_t index, int value) { publish(topics[index], String(value)); };
}

BoolCallback ControlAnything::addOutput(const Output<DataType::BOOL>& output)
{
    output.dumpJson(json["outputs"].as<JsonArray>().add<JsonObject>());
    std::vector<String> topics = output.topics;
    return [this, topics](uint8_t index, bool value) { publish(topics[index], String(value)); };
}

FloatCallback ControlAnything::addOutput(const Output<DataType::FLOAT>& output)
{
    output.dumpJson(json["outputs"].as<JsonArray>().add<JsonObject>());
    std::vector<String> topics = output.topics;
    return [this, topics](uint8_t index, float value) { publish(topics[index], String(value)); };
}

StringCallback ControlAnything::addOutput(const Output<DataType::STRING>& output)
{
    output.dumpJson(json["outputs"].as<JsonArray>().add<JsonObject>());
    std::vector<String> topics = output.topics;
    return [this, topics](uint8_t index, String value) { publish(topics[index], value); };
}
