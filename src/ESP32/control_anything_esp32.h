#pragma once

#include <Arduino.h>
#include "control_anything.h"

class ControlAnythingEsp32 : public ControlAnything {

    public:
        ControlAnythingEsp32();
        virtual void initialize(bool host) override;
        virtual void start() override;

    protected:
        virtual void subscribe(String topic, std::function<void(String)>) override;

};