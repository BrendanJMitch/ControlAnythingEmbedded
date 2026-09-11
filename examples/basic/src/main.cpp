#include <Arduino.h>
#include <control_anything.h>
#include "schema/data_type.h"
#include "schema/control.h"
#include "schema/toggle_widget.h"
#include "schema/numeric_output_widget.h"

ControlAnything& controlAnything = ControlAnything::get();
const uint8_t RED_LED_PIN = 3;
const uint8_t BATTERY_VOLTAGE_PIN = 4;
FloatCallback publishBatteryVoltage;
float voltage;

void setRedLed(uint8_t, bool state){
    digitalWrite(RED_LED_PIN, state);
}

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

    /* Register a control attached to the "controls/red_led" topic with 
    the callback `setRedLed`. */
    controlAnything.addControl(
        Control<DataType::BOOL>(
            std::array<String, 1>{"red_led"},
            "Red LED",  
            ToggleWidget(true)    
        ),
        setRedLed   
    );

    /* Register an output attached to the topic outputs/battery_voltage
    and obtain a callback for publishing the value. */
    publishBatteryVoltage = controlAnything.addOutput(
        Output<DataType::FLOAT>(
            std::array<String, 1>{"battery_voltage"},
            "Battery",
            NumericOutputWidget("V")
        )
    );

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
    publishBatteryVoltage(0, voltage);
}
