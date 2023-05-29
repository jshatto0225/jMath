#include "jMath/Vector.h"
#include <iostream>

namespace jMath
{
	Vector::Vector()
	{

	}

	Vector::Vector(DataType type)
		: m_Dtype(type), m_Length(0)
	{
		// TODO: Create buffer
	}

	Vector::Vector(DataType type, ll length)
		: m_Dtype(type), m_Length(length)
	{
		m_Size = SizeOfType(type) * m_Length;
		// TODO: Create buffer
	}

	Vector::Vector(Allocator* a, DataType type, ll length){}
	Vector::Vector(Allocator* a, DataType type, ll length, AllocationAttributes allocation_arrtibs){}

	Vector::Vector(DataType type, ll length, VectorBuffer* buffer)
		: m_Dtype(type), m_Length(length), m_Buffer(buffer)
	{
		m_Size = SizeOfType(type) * m_Length;
	}

	Vector::Vector(DataType type, ll length, std::unique_ptr<VectorBuffer> buffer)
		: m_Dtype(type), m_Length(length), m_Buffer(buffer.release())
	{
		m_Size = SizeOfType(type) * m_Length;
	}

	Vector::Vector(const Vector& other)
	{
		
	}

	Vector::Vector(Vector&& other)
	{
		
	}

	Vector::~Vector()
	{
		// TODO: Delete buffer
	}

	Vector& Vector::operator=(const Vector& other)
	{
		return *this;
	}

	Vector& Vector::operator=(Vector&& other)
	{
		return *this;
	}

	void Vector::SetLength(ll newLength)
	{

	}

	std::ostream& operator<<(std::ostream& out, const Vector& vector)
	{
		for (int i = 0; i < vector.m_Length; i++) 
		{
			switch (vector.m_Dtype)
			{
			case DT_FLOAT:				out << vector.m_Buffer->GetTypedData<float>()[i];
			case DT_DOUBLE:				out << vector.m_Buffer->GetTypedData<double>()[i];
			case DT_INT:				out << vector.m_Buffer->GetTypedData<int32>()[i];
			case DT_UNSIGNED_INT:		out << vector.m_Buffer->GetTypedData<uint32>()[i];
			case DT_SHORT:				out << vector.m_Buffer->GetTypedData<int16>()[i];
			case DT_UNSIGNED_SHORT:		out << vector.m_Buffer->GetTypedData<uint16>()[i];
			case DT_LONG_LONG:			out << vector.m_Buffer->GetTypedData<int64>()[i];
			case DT_UNSIGNED_LONG_LONG: out << vector.m_Buffer->GetTypedData<uint64>()[i];
			case DT_BOOL:				out << vector.m_Buffer->GetTypedData<bool>()[i];
			case DT_CHAR:				out << vector.m_Buffer->GetTypedData<int8>()[i];
			case DT_UNSIGNED_CHAR:		out << vector.m_Buffer->GetTypedData<uint8>()[i];
			default:					__debugbreak();
			}
			out << "\n";
		}

		return out;
	}
}
