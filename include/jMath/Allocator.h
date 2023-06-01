#pragma once

#include "DataTypes.h"

namespace jMath
{

    enum DeviceType
    {
        CPU,
        GPU
    };

	/// <summary>
	/// Struct that can store allocation attributes
	/// </summary>
	struct AllocationAttributes
	{
        AllocationAttributes(bool packed = false, DeviceType device = CPU)
            : Packed(packed), Device(device) {}
		bool Packed;
        DeviceType Device;
	};
	
    /// <summary>
	///  Class to handle all data allocation
	/// </summary>
	class Allocator
	{
        void Allocate(AllocationAttributes allocation_attribs = AllocationAttributes());
	};

	/// <summary>
	/// Struct to store the stats of the allcoator
	/// </summary>
	struct AllocatorStats
	{
		ll BytesAllocated;
		ll BuffersAllocated;
        ll LinkedBuffers;
	};
}
