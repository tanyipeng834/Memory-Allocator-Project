
#include "free_list.h"
#include <stdio.h>
#include <stdlib.h>







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