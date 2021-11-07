#include "memory.h"
#include <exception>
#include <string.h>

#define memzero(base, size)		\
	memset(base,0,size);

struct alloc_denied : public std::exception 
{
	const char* what() const noexcept { return "new failed!"; }
};

void* smart_new(size_t mem_size)
{
	void* mem_block = new void*[mem_size];
	if (mem_block == nullptr)
	{
		throw alloc_denied {};
	}

	memzero(mem_block, mem_size);
	return mem_block;
}