#ifndef FREE_LIST_H
#define FREE_LIST_H
#define MAGIC_NUMBER 1234567
#include <stdio.h>
// This is used to keep track of all free memory regions in VM.
typedef struct node
{

    int size ;
    struct node* next;

    
} node_t;
// This header is used for allocated memory regions.


typedef struct block_header
{

    size_t size ;
    int is_free;

    
} block_header_t;

block_header_t * buddy_head; 
size_t memory_base_size;


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






