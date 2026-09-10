#pragma once

#include "Arduino.h"

enum class DataType { INT, BOOL, FLOAT, STRING };

template<DataType DT> struct DataTypeOf;

template<> struct DataTypeOf<DataType::BOOL>  {
     static constexpr const char* value = "bool";
};
template<> struct DataTypeOf<DataType::FLOAT> {
     static constexpr const char* value = "float";
};
template<> struct DataTypeOf<DataType::INT>  {
     static constexpr const char* value = "int";
};
template<> struct DataTypeOf<DataType::STRING> {
     static constexpr const char* value = "string";
};

