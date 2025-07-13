#include "mem.h"
#include <unistd.h>
#include <stdio.h>
#include <sys/mman.h>
#include "free_list.h"


node_t * head = NULL;
int Mem_Init(int sizeOfRegion){
    if (sizeOfRegion<=0){
        return -11;
    }
    int pageSize = getpagesize();
    int pagesRequested = sizeOfRegion / pageSize;
    int memoryRequest = pageSize * pagesRequested;
    head = mmap(NULL, memoryRequest, PROT_READ | PROT_WRITE,
                        MAP_ANON | MAP_PRIVATE, -1, 0);
    head ->size = memoryRequest - sizeof(node_t);
    head ->next = NULL;


    if (head == MAP_FAILED) {
        perror("mmap failed");
        return -1;
    }
    else{
        return 0;
    }




    


}



int main(int argc , char*argv[]){
    printf("%d",Mem_Init(100));

}


