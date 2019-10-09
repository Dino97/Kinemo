#pragma once

#include "KinemoTypes.h"

namespace Kinemo { namespace Memory { namespace Allocator {

	static inline uint8 GetAdjustment(const void* address, uint8 alignment)
	{
		uint8 adjustment = alignment - (reinterpret_cast<uintptr_t>(address) & static_cast<uintptr_t>(alignment - 1));

		return adjustment == alignment ? 0 : adjustment;
	}

	class IAllocator
	{
	protected:
		const size_t m_MemorySize;
		const void* m_MemoryFirstAddress;

		size_t m_MemoryUsed;
		uint64 m_MemoryAllocations;

	public:
		IAllocator(const size_t memSize, const void* mem);
		virtual ~IAllocator();

		virtual void* Allocate(size_t size, uint8 alignment) = 0;
		virtual void Free(void* p) = 0;
		virtual void Clear() = 0;

		inline size_t GetMemorySize() const 
		{ 
			return m_MemorySize; 
		}

		inline const void* GetMemoryAdress0() const 
		{ 
			return m_MemoryFirstAddress; 
		}

		inline size_t GetMemoryUsed() const 
		{ 
			return m_MemoryUsed; 
		}

		inline uint64 GetMemoryAllocationCount() const
		{
			return m_MemoryAllocations;
		}
	};

}}}