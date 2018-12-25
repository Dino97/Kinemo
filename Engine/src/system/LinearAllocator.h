#pragma once

#include "IAllocator.h"

namespace Kinemo { namespace Memory { namespace Allocator { 

	class LinearAllocator : public IAllocator
	{
	public:
		LinearAllocator(size_t memSize, const void* mem);
		virtual ~LinearAllocator();

		virtual void* Allocate(size_t size, uint8 alignment) override;
		virtual void Free(void* p) override;
		virtual void Clear() override;

	}; // class Linear Allocator

}}} // namespace Kinemo::Memory::Allocator