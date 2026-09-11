#pragma once

#include <Arduino.h>
#include <vector>

// TODO: All JSON string operations should be rewritten to minimize heap fragmentation

class Serializable
{

    public:
        static constexpr const char* TAB = "    ";
        virtual const String dumpJson(const uint8_t indentLevel) const = 0;

    protected:
        template <typename T>
        static const String keyValToJson(const uint8_t indentLevel, const String key, T val)
        {
            return getIndent(indentLevel) + "\"" + key + "\": \"" + String(val) + "\",\r\n";
        }

        template <typename T>
        static const String vectorToJson(const uint8_t indentLevel, const std::vector<T> list)
        {
            String json = "[\r\n";
            String indent = getIndent(indentLevel);
            for (T item : list)
            {
                json += indent + TAB + "\"" + String(item) + "\",\r\n";
            }
            json += indent + "]";
            return json;
        }

        static const String getIndent(const uint8_t indentLevel)
        {
            String result;
            result.reserve(indentLevel * 4);
            for (uint8_t i = 0; i < indentLevel; ++i)
                result += TAB;
            return result;
        }
};
