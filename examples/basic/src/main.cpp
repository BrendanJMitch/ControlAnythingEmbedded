#include <Arduino.h>
#include <control_anything.h>
#include "schema/control.h"

ControlAnything& controlAnything = ControlAnything::get();
const uint8_t RED_LED_PIN = 3;
const uint8_t BATTERY_VOLTAGE_PIN = 4;
FloatFunc publishBatteryVoltage;
float voltage;

void setup() {

    pinMode(RED_LED_PIN, OUTPUT);

    controlAnything.setNetworkSSID("Robot Access Point");
    controlAnything.setNetworkPassword("i<3robots");
    controlAnything.setDeviceName("LED Robot 1");
    controlAnything.setProjectId("led_robot");

    /* Setup networking. If parameter `host` is true, set up a WiFi 
    access point with the provided SSID and password. Otherwise, connect
    to a network with the SSID and password. Once done, host an MQTT 
    broker. */
    controlAnything.initialize(true);

    /* Register Controls and Outputs */

    /* Publish an `info` topic which contains a single json string with
    all the information that the android app needs to create a dashboard
    of widgets for all the registered controls and outputs. In this case, 
    the json would look like this:
    {
        "device_id": "esp32-fake-01",
        "device_name": "LED Robot 1",
        "project_id": "led_robot",
        "schema_hash": "demo1",
        "controls": [
            {
                "topic": ["red_led"],
                "display_name": "Red LED",
                "type": "bool",
                "widget": {"type": "toggle", "default_value": True},
            },
        ],
        "outputs": [
            {
                "topic": ["battery_voltage"],
                "display_name": "Battery",
                "type": "float",
                "widget": {"type": "numeric_output", "suffix": "V"},
            },
        ],
    }
    Then advertise the broker for auto discovery.*/
    controlAnything.start();
}

void loop() {
    voltage = analogRead(BATTERY_VOLTAGE_PIN) / 100.0;
    publishBatteryVoltage(voltage);
}
