#pragma once

#include <stdint.h>
#include <vector>
#include <string>

#define int8_name "signed cahr"
#define int16_name "short"
#define int32_name "int"
#define int64_name "__int64"
#define uint8_name "unsigned char"
#define uint16_name "unsigned short"
#define uint32_name "unsigned int"
#define uint64_name "unsigned __int64"
#define double_name "double"
#define float_name "float"
#define bool_name "bool"
#define void_name "void"

/// <summary>
/// Rename type
/// </summary>
typedef int8_t int8;
typedef int16_t int16;
typedef int32_t int32;
typedef int64_t int64;
typedef uint8_t uint8;
typedef uint16_t uint16;
typedef uint32_t uint32;
typedef uint64_t uint64;

typedef unsigned long long ull;
typedef long long ll;

typedef uint8_t byte;

using std::vector;

/// <summary>
/// Enum of possible datatypes
/// </summary>
enum DataType
{
	DT_FLOAT,
	DT_DOUBLE,
	DT_INT,
	DT_UNSIGNED_INT,
	DT_SHORT,
	DT_UNSIGNED_SHORT,
	DT_LONG_LONG,
	DT_UNSIGNED_LONG_LONG,
	DT_BOOL,
	DT_CHAR,
	DT_UNSIGNED_CHAR,

	DT_UINT = DT_UNSIGNED_INT,
	DT_USHORT = DT_UNSIGNED_SHORT,
	DT_LL = DT_LONG_LONG,
	DT_ULL = DT_UNSIGNED_LONG_LONG,
	DT_BYTE = DT_UNSIGNED_CHAR,
	DT_UCHAR = DT_UNSIGNED_CHAR
};

size_t SizeOfType(DataType type)
{
	switch (type)
	{
	case DT_FLOAT:				return 4;
	case DT_DOUBLE:				return 8;
	case DT_INT:				return 4;
	case DT_UNSIGNED_INT:		return 4;
	case DT_SHORT:				return 2;
	case DT_UNSIGNED_SHORT:		return 2;
	case DT_LONG_LONG:			return 8;
	case DT_UNSIGNED_LONG_LONG: return 8;
	case DT_BOOL:				return 1;
	case DT_CHAR:				return 1;
	case DT_UNSIGNED_CHAR:		return 1;
	default:					return 0;
	}
}

std::string __type_name(DataType type)
{
	switch (type)
	{
	case DT_FLOAT:				return float_name;
	case DT_DOUBLE:				return double_name;
	case DT_INT:				return int32_name;
	case DT_UNSIGNED_INT:		return uint32_name;
	case DT_SHORT:				return int16_name;
	case DT_UNSIGNED_SHORT:		return uint16_name;
	case DT_LONG_LONG:			return int64_name;
	case DT_UNSIGNED_LONG_LONG: return uint64_name;
	case DT_BOOL:				return bool_name;
	case DT_CHAR:				return int8_name;
	case DT_UNSIGNED_CHAR:		return uint8_name;
	default:					return void_name;
	}
}

bool __same_type(DataType type, std::string name)
{
	return __type_name(type) == name;
}