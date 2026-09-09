#include "output.h"

Output::Output(std::vector<String> topics, String displayName, const Widget &widget)
    : IO(topics, displayName, widget)
{
}

const String Output::dumpJson(String leadingWhitespace) const
{
    return dumpJsonImpl(leadingWhitespace);
}