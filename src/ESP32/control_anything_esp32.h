#pragma once

#include <Arduino.h>
#include "control_anything.h"

class ControlAnythingEsp32 : public ControlAnything {

    public:
        ControlAnythingEsp32();
        virtual void initialize(bool host);
        virtual void start();

    protected:
        virtual void subscribe(String topic, StrFunc callback);

};