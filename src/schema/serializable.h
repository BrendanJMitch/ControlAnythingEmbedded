#pragma once

#include <Arduino.h>
#include <vector>


class Serializable {

    public:
        static constexpr const char* TAB = "    ";
        virtual const String dumpJson(String leadingWhitespace) const = 0;

    protected:

        template <typename T>
        const String keyValToJson(String key, T val, String leadingWhitespace) const {
            return leadingWhitespace + "\"" + key + "\": \"" + String(val) + "\",\r\n";
        }

        template <typename T>
        const String vectorToJson(std::vector<T> list, String leadingWhitespace) const {
            String json = "[\r\n";
            for (T item : list){
                json += leadingWhitespace + TAB + "\"" + String(item) + "\",\r\n";
            }
            json += leadingWhitespace + "]";
            return json;
        }
};

