#pragma once

#include "control_anything.h"
#include <Arduino.h>

class ControlAnythingEsp32 : public ControlAnything
{

    public:
        ControlAnythingEsp32();
        virtual void initialize(bool host) override;
        virtual void start() override;

    protected:
        virtual void subscribe(String topic, std::function<void(String)>) override;
};

using ControlAnythingImpl = ControlAnythingEsp32;