#ifndef FREE_LIST_H
#define FREE_LIST_H
typedef struct node
{

    int size ;
    struct node* next;

    
} node_t;

typedef struct{
    int size ;
    int magic;
    } header;

#endif

extern node_t * head;

void 


