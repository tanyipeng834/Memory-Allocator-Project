#ifndef MEM_H
#define MEM_H
#include "free_list.h"
int Mem_Init(int sizeOfRegion);
// Should return 8 byte-aligned memory
void *Mem_Alloc(int size);

int Mem_Free(void * ptr);

int Mem_Available();

void Mem_Dump();
void coalesc_memory(node_t * head);

#endif