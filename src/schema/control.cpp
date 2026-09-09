#include "control.h"

Control::Control(std::vector<String> topics, String displayName, const Widget &widget)
    : IO(topics, displayName, widget)
{
}

const String Control::dumpJson(String leadingWhitespace) const
{
    return dumpJsonImpl(leadingWhitespace);
}
