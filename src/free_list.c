
#include "free_list.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>








// First fit implementation
void * first_fit(int memory_request)
{   
    
    size_t total_memory_request = sizeof(node_t) +((memory_request/8)+1)*8;
    
    
    node_t ** link = &head;


    while (*link!=NULL)
    {
        node_t * current_block = *link;
        if(current_block->size>= total_memory_request){
            // Total memory left
            int total_memory_left = current_block->size - total_memory_request;
            
            
            if(current_block->size>total_memory_request)
            {
                node_t * remainder = (node_t *)((char *) current_block + total_memory_request) ;
                remainder ->size = total_memory_left;
                remainder ->next = NULL;

                *link = remainder;

            }
            else if (current_block->size == total_memory_request){
                // use up the entire block
                *link = current_block->next;


            }
                header * h = (header *) current_block;
                h ->size = total_memory_request;
                h ->magic = MAGIC_NUMBER;
                


                return (void*)(h+1);





            
            
           


             

             





        }


        link = &(current_block->next);


    }
    return NULL;





}




void * best_fit(int memory_request)
{   
    size_t total_memory_request = sizeof(node_t) +((memory_request/8)+1)*8;
    
    node_t ** link = &head;

    node_t ** node_to_replace = NULL;
    size_t best_fit_size =SIZE_MAX;


    while (*link!=NULL)
    {
        node_t * current_block = *link;
        
        if(current_block->size>= total_memory_request && current_block->size<best_fit_size){
            node_to_replace = link;

            

            
        }
        link = &(current_block->next);
    }

    if(!node_to_replace) return NULL;
        node_t* best_fit_block = *node_to_replace;
        if(best_fit_block->size>total_memory_request)
            {
                size_t total_memory_left = best_fit_block->size - total_memory_request;
                node_t * remainder = (node_t *)((char *) best_fit_block + total_memory_request);
                remainder ->size = total_memory_left;
                remainder ->next = NULL;

                *node_to_replace = remainder;

            }
            else if (total_memory_request == best_fit_block->size){
                // use up the entire block
                *node_to_replace = best_fit_block->next;


            }
                header * h = (header *) best_fit_block;
                h ->size = total_memory_request;
                h ->magic = MAGIC_NUMBER;
                


                return (void*)(h+1);




   





}


int buddy_init()
{
    if(head ==NULL){
        perror("Memory has not been mapped to the virtual address space.");
        return -1;
        
    }
    // If we are using buddy alloaction then, we no longer need the free list header
    else{
        // this is the starting address of the 
        buddy_head = (block_header_t*)(head);
        memory_base_size = head->size + sizeof(node_t);
        buddy_head->is_free =0;
        return 0;
    
    
    
    
    }

    
    

}

// void * buddy_allocate(int memory_size)
// {
    
//         size_t total_memory_request = sizeof(block_header_t) +((memory_size/8)+1)*8;
//         size_t max_power = log2(memory_base_size);
        
//         int memory_request_power = get_lowest_block_size(memory_base_size,total_memory_request,max_power);
//         printf("The lowest power that I have is:%d",memory_request_power);
//         size_t block_size = pow(2, memory_request_power);
//         char * walk = (char *)buddy_head;
//         // Iterate until the last possible block
//         char* walk_end = walk +memory_base_size - block_size;
//        while (walk <= walk_end) {
//         block_header_t *header = (block_header_t *)walk;
//         if (header->is_free != 1) {
//         return (void *)(header + 1);
//     }


            
//             char * walk  = ((char*)(walk)) +block_size;

//         }
        
//     }

    




    



int get_lowest_block_size(size_t total_memory,int memory_request,int max_power){
    
    
    while(total_memory>=memory_request)
    {


        // unsigned right shift
        total_memory = total_memory>>1;
        max_power -=1;


    }
    return max_power+=1;
}


void * buddy_allocation(int memory_size,block_header_t* current_block)

{   
   

    size_t required_size = memory_size + sizeof(block_header_t);
    


    
    if(!current_block || current_block->is_free){
        return NULL;
    }

    if(current_block->size<required_size){
        return NULL;
    }

    if(current_block->size<required_size*2){
        current_block->is_free =1;
        printf("current block%p",current_block );
        return (void*) (current_block+1);

    }

    size_t half_size = current_block->size /2;
    
    block_header_t * left_child = current_block;

    block_header_t * right_child = (block_header_t*)((char *)current_block + half_size);

    left_child->size = half_size;
    left_child->is_free = 0;

    right_child->size = half_size;
    right_child->is_free = 0;

    
    void* result = buddy_allocation(memory_size, left_child);
    if (result != NULL) return result;

  
    return buddy_allocation(memory_size, right_child);


    



}



