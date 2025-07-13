int Mem_Init(int sizeOfRegion);
// Should return 8 byte-aligned memory
void *Mem_Alloc(int size);

int Mem_Free(void * ptr);

int Mem_Available();

void Mem_Dump();