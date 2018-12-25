#include "LinearAllocator.h"

namespace Kinemo { namespace Memory { namespace Allocator {
	
	LinearAllocator::LinearAllocator(size_t memSize, const void* mem) :
		IAllocator(memSize, mem)
	{}

	LinearAllocator::~LinearAllocator()
	{
		this->Clear();
	}

	void* LinearAllocator::Allocate(size_t size, uint8 alignment)
	{
		// log this
		if (size == 0)
			return nullptr;

		union
		{
			void* asVoidPtr;
			uintptr_t asUptr;
		};

		asVoidPtr = (void*)this->m_MemoryFirstAddress;

		// current address
		asUptr += this->m_MemoryUsed;

		// get Adjustment to align address
		uint8 adjustment = GetAdjustment(asVoidPtr, alignment);

		// check if there is enough memory available
		if (this->m_MemoryUsed + size + adjustment > this->m_MemorySize)
		{
			// not enough memory
			return nullptr;
		}

		// determine aligned memory address
		asUptr += adjustment;

		// update allocator data
		this->m_MemoryUsed += size + adjustment;
		this->m_MemoryAllocations++;

		// return aligned memory address
		return asVoidPtr;
	}

	void LinearAllocator::Free(void* p)
	{
		// assert(false);
		// LinearAllocator does not support free operation. Use clear instead.
	}

	void LinearAllocator::Clear()
	{
		// simply reset memory
		this->m_MemoryUsed = 0;
		this->m_MemoryAllocations = 0;
	}

}}} // namespace Kinemo::Memory::Allocator