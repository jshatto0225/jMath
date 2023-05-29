#pragma once

#include "DataTypes.h"
#include "Allocator.h"
#include <memory>

namespace jMath
{
	/// <summary>
	/// Class to handle raw vector data
	/// </summary>
	class VectorBuffer
	{
	public:
		/// <summary>
		/// Create vector buffer containing data
		/// </summary>
		/// 
		/// <param name="data">
		/// pointer to the data being used
		/// </param>
		VectorBuffer(void* data) : m_Data(data) {}

		/// <summary>
		/// Function to get the location of the raw data
		/// </summary>
		/// 
		/// <returns>
		/// Pointer to raw data
		/// </returns>
		void* GetRawData() const { return m_Data; }

		/// <summary>
		/// Templated function to get raw data as a specific type
		/// </summary>
		/// 
		/// <typeparam name="T">
		/// Type of the data that will be retrieved
		/// </typeparam>
		/// 
		/// <returns>
		/// Pointer to data casted as type T
		/// </returns>
		template<typename T>
		T* GetTypedData() { return reinterpret_cast<T*>(m_Data); }

		/// <summary>
		/// Templated function to get const raw data as a specific type
		/// </summary>
		/// 
		/// <typeparam name="T">
		/// Type of the data that will be retrieved
		/// </typeparam>
		/// 
		/// <returns>
		/// Pointer to data casted as type T
		/// </returns>
		template<typename T>
		T* GetTypedData() const { return reinterpret_cast<T*>(m_Data); }

	private:
		void* m_Data;
	};

	/// <summary>
	/// Vector class
	/// Can access and modify vector data
	/// </summary>
	class Vector
	{
	public:
		/// <summary>
		/// Constructor for empty float vector
		/// </summary>
		Vector();

		/// <summary>
		/// Contructor for vector of given type
		/// </summary>
		/// 
		/// <param name="type">
		/// Type of data to be stored
		/// </param>
		Vector(DataType type);

		/// <summary>
		/// Constructor for vector with given type and length
		/// </summary>
		/// 
		/// <param name="type">
		/// Type of data to be stored
		/// </param>
		/// 
		/// <param name="length">
		/// Length of vector to be created
		/// </param>
		Vector(DataType type, ll length);

		/// <summary>
		/// Constructor for vector with given type and length, using the allocator a
		/// </summary>
		/// 
		/// <param name="a"
		/// Allocator to be used to allocate the underlying buffer
		/// </param>
		/// 
		/// <param name="type">
		/// Type of data to be stored
		/// </param>
		/// 
		/// <param name="length">
		/// Length of vector to be created
		/// </param>
		Vector(Allocator* a, DataType type, ll length);

		/// <summary>
		/// Constructor for vector with given type and length, using the allocator a and allocation_attribs
		/// </summary>
		/// 
		/// <param name="a"
		/// Allocator to be used to allocate the underlying buffer
		/// </param>
		/// 
		/// <param name="type">
		/// Type of data to be stored
		/// </param>
		/// 
		/// <param name="length">
		/// Length of vector to be created
		/// </param>
		/// 
		/// <param name="allocation_attribs"
		/// Attributes to be used durrring allocation
		/// </param>
		Vector(Allocator* a, DataType type, ll length, AllocationAttributes allocation_arrtibs);

		/// <summary>
		/// Constructor for vector with given type, length, and buffer
		/// </summary>
		/// 
		/// <param name="type">
		/// Type of data to be stored
		/// </param>
		/// 
		/// <param name="length">
		/// Length of vector to be created
		/// </param>
		/// 
		/// <param name="buffer">
		/// Buffer to get data from
		/// </param>
		Vector(DataType type, ll length, VectorBuffer* buffer);

		/// <summary>
		/// Constructor for vector with given type, length, and buffer
		/// </summary>
		/// 
		/// <param name="type">
		/// Type of data to be stored
		/// </param>
		/// 
		/// <param name="length">
		/// Length of vector to be created
		/// </param>
		/// 
		/// <param name="buffer">
		/// Buffer to get data from
		/// </param>
		Vector(DataType type, ll length, std::unique_ptr<VectorBuffer> buffer);

		/// <summary>
		/// Copy constructor
		/// Other vector is safe to delete
		/// </summary>
		/// 
		/// <param name="other">
		/// Vector to copy
		/// </param>
		Vector(const Vector& other);

		/// <summary>
		/// Move contructor
		/// Other vector is safe to delete
		/// </summary>
		/// 
		/// <param name="other">
		/// Vector to move
		/// </param>
		Vector(Vector&& other);

		/// <summary>
		/// Destructor
		/// </summary>
		~Vector();

		/// <summary>
		/// Copy operator
		/// </summary>
		/// 
		/// <param name="other">
		/// Vector to be copies
		/// </param>
		/// 
		/// <returns>
		/// Copied vector
		/// </returns>
		Vector& operator=(const Vector& other);

		/// <summary>
		/// Move operator
		/// </summary>
		/// 
		/// <param name="other">
		/// Vector to move
		/// </param>
		/// 
		/// <returns>
		/// Moved vector
		/// </returns>
		Vector& operator=(Vector&& other);

		friend std::ostream& operator<<(std::ostream& out, const Vector& vector); /// I/O operator

		/// <summary>
		/// Gettot for the size in bytes of the vector
		/// </summary>
		/// 
		/// <returns>
		/// Size of the vector in bytes
		/// </returns>
		ll Size() { return m_Size; }

		/// <summary>
		/// Getter for the number of items
		/// </summary>
		/// 
		/// <returns>
		/// Number of items in the vector
		/// </returns>
		ll Length() { return m_Length; }

		template<typename T>
		T operator()(ll index);

		/// <summary>
		/// Set a new length for the vector
		/// </summary>
		/// 
		/// <param name="newLength">
		/// Length to be set
		/// </param>
		void SetLength(ll newLength);

	private:
		VectorBuffer* m_Buffer;
		ll m_Length, m_Size;
		DataType m_Dtype;
	};

	template<typename T>
	inline T Vector::operator()(ll index)
	{
		if(index < m_Length && __same_type(m_Dtype, typeid(T).name()))
			return m_Buffer->GetTypedData<T>()[index];
		// TODO: break based on platform
		__debugbreak();
	}
}
