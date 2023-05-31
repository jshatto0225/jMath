#pragma once

#include "DataTypes.h"

namespace jMath
{

	/// <summary>
	///  Class to handle all data allocation
	/// </summary>
	class Allocator
	{
	};

	/// <summary>
	/// Struct that can store allocation attributes
	/// </summary>
	struct AllocationAttributes
	{
		bool Packed;
	};

	/// <summary>
	/// Struct to store the stats of the allcoator
	/// </summary>
	struct AllocatorStats
	{
		ll BytesAllocated;
		ll BuffersAllocated;
	};
}
