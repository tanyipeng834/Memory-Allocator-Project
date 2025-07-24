#ifndef FREE_LIST_H
#define FREE_LIST_H
#define MAGIC_NUMBER 1234567

// This is used to keep track of all free memory regions in VM.
typedef struct node
{

    int size ;
    struct node* next;

    
} node_t;
// This header is used for allocated memory regions.

void * memory_base; 
int full_memory_space;
typedef struct{
    int size ;
    int magic;
    } header;






// This is the  head of the free list.
extern node_t * head;



void * first_fit (int memoryRequest);
void * best_fit (int memoryRequest);
// Return status code based on the status of memory being allocated.
int buddy_init();
#endif






