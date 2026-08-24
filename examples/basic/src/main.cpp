#include <Arduino.h>
#include <ControlAnythingESP32.h>

ControlAnythingESP32 thing(LED_BUILTIN);

void setup() {
    thing.begin();
}

void loop() {
    thing.update();
    delay(500);
}
