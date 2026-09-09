#include "io.h"

IO::IO(std::vector<String> topics, String displayName, const Widget &widget)
    : topics(topics), displayName(displayName), widget(widget.clone()) 
{
}

const String IO::dumpJsonImpl(String leadingWhitespace) const
{
    return
        leadingWhitespace + "{\r\n" +
        leadingWhitespace + TAB + keyValToJson("topics", vectorToJson(topics, leadingWhitespace + TAB), leadingWhitespace + TAB) +
        leadingWhitespace + TAB + keyValToJson("displayName", displayName, leadingWhitespace + TAB) +
        leadingWhitespace + TAB + keyValToJson("widget", widget->dumpJson(leadingWhitespace + TAB), leadingWhitespace + TAB) + 
        leadingWhitespace + "}";
}