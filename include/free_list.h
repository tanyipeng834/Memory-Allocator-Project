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
typedef struct{
    int size ;
    int magic;
    } header;

#endif

extern node_t * head;

void * first_fit (int memoryRequest);






