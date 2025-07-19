#include "mem.h"
#include <unistd.h>
#include <stdio.h>
#include <sys/mman.h>
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


void Mem_Dump()
{
    if(head!=NULL){
        node_t * walk = head;
        while(walk!=NULL)
        {

            printf("Memory Block Available: %d",walk->size);

            walk = walk->next;


        }



    }
    else{
        printf("Memory has not been allocated for the heap");
    }
    

}



int main(int argc , char*argv[]){
   // Allocate Memory
   Mem_Init(1000);

   Mem_Dump();

   

}


