#include "IAllocator.h"

namespace Kinemo { namespace Memory { namespace Allocator {

	IAllocator::IAllocator(const size_t memSize, const void* mem) : 
		m_MemorySize(memSize), 
		m_MemoryFirstAddress(mem), 
		m_MemoryUsed(0), 
		m_MemoryAllocations(0)
	{}

	IAllocator::~IAllocator()
	{}

}}} // namespace Kinemo::Memory::Allocator