#include "mem.h"
#include <unistd.h>
#include <stdio.h>
#include <sys/mman.h>
#include <string.h>
#include "free_list.h"


node_t * head = NULL;
int Mem_Init(int sizeOfRegion){
    if (sizeOfRegion<=0){
        return -1;
    }
    int pageSize = getpagesize();
    // page size of mac book is 16384 bytes
    
    int pagesRequested = (sizeOfRegion / pageSize)+1;
    int memoryRequest = pageSize * pagesRequested;
    head = mmap(NULL, memoryRequest, PROT_READ | PROT_WRITE,
                        MAP_ANON | MAP_PRIVATE, -1, 0);
    
    


    if (head == MAP_FAILED) {
        perror("mmap failed");
        return -1;
    }
    else{
    head ->size = memoryRequest - sizeof(node_t);
    head ->next = NULL;
        return 0;
    }




    


}

void * Mem_Alloc(int size){
    return first_fit(size);
}


int Mem_Free(void * ptr)
{
    // Check if the ptr was returned by mem_alloc
    
    
    if (ptr!=NULL)
    {
       
        header * h = ((header *) ptr)-1;
        

        


        
        
        if(h->magic ==MAGIC_NUMBER){
            

            int size_block = h->size;
            node_t *free_node = (node_t* )(h);
            free_node->size = size_block;
            node_t ** current_block = &head;
            // This will iterate till the end or when they find a block that is before the current block
            while(*current_block!=NULL && *current_block<free_node)
            {
                current_block =&((*current_block)->next);
            }
            free_node ->next=*current_block;
            *current_block= free_node;
            return 0;





        }

        else{


            return -1;
            
        }



    }

    return -1;
    
    


} 


void Mem_Dump()
{
    if(head!=NULL){
        node_t * walk = head;
        while(walk!=NULL)
        {

            printf("Memory Block Available: %d\n",walk->size);

            walk = walk->next;


        }



    }
    else{
        printf("Memory has not been allocated for the heap\n");
    }
    

}

int mem_available(){
    size_t memory_available =0;
    if(head!=NULL)
    {
        node_t * walk = head;
        while(walk!=NULL){
            memory_available += walk->size;
            walk= walk->next;   
        }

    }
    return memory_available;
}



int main(int argc , char*argv[]){
   // Allocate Memory
   Mem_Init(1000);

   Mem_Dump();
    // Take into account the null character of hello for testing
   
   char *string = (char *)Mem_Alloc(sizeof(char)*6);
    strcpy(string, "hello");

   printf("character here:%c\n",*string);

   
   Mem_Free(string);
   // This should print out the free space available.
   Mem_Dump();


   

}


