
# Memory Alloctor Project


This Memory Alloctor Project is based on on the OSTEP textbook and it's projects with the specifications listed [here](https://pages.cs.wisc.edu/~cs537-3/Projects/p3a.html).


## Dependencies

The project has the following dependencies:
- `make`
- `gcc` 


## Building


To build and run the docker image, you can do the following:
```
make all
```
By running the above command, it would make run `mem.c` which would be used as the api for allocating memory and freeing memory.
## Key Features
1. First Fit Memory Allocation Strategy
2. Best Fit Memory Allocation Strategy
3. Buddy Allocation Strategy
4. Coalescing of memory to prevent external fragmentation

## Functions
`void Mem_init(int size)` This function is used to allocate virtual memory for the programn by using `mmap` which maps anoynomous memory to the process's virtual space.
`void * Mem_Alloc(int size)` This functions returns a void pointer that points to a memory defined in the parameter.The size of the memory returned will be 8-byte aligned for the CPU.
`void * Mem_Free(void* ptr)` This functions is used to free the memory that is stored in the pointer.
`void Mem_Dump()` This function is used to iterate through the free list which shows the memory available for the memory chunks on the free list.
`void Mem_Available()` This function is used to check the total avaialble virtual memory available for the process.

### Future Works

- [ ] Add more functions like `calloc` and `realloc` functionality for the memory alloctor





