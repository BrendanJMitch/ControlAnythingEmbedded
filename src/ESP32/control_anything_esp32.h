#pragma once

#include <Arduino.h>
#include <functional>

#include "control_anything.h"

class ControlAnythingEsp32 : public ControlAnything
{
        friend class ControlAnything;

    public:
        virtual void initialize(bool host) override;
        virtual void start() override;

    protected:
        virtual void subscribe(String topic, std::function<void(String)>) override;

    private:
        ControlAnythingEsp32();
};

using ControlAnythingImpl = ControlAnythingEsp32;