
#include "free_list.h"






// First fit implementation
void * first_fit(int memory_request)
{   
    int total_memory_request = sizeof(header);
    total_memory_request = total_memory_request+ ((memory_request/8)+1)*8;
    
    node_t ** link = &head


    while (*link!=NULL)
    {
        node_t * current_block = *link;
        if(current_block->size>= total_memory_request){
            // Total memory left
            int total_memory_left = walk->size - total_memory_request;
            
            
            if(current_block->size>total_memory_request)
            {
                
                node_t * remainder = (node_t *)(char *) current_block + total_memory_request;
                remainder ->size = total_memory_left;
                remainder ->next = NULL;

                *link = remainder

            }
            else{
                // use up the entire block
                *link = current_block->next;


            }
                header * h = (header *) current_block;
                h ->size = memory_request;
                h ->magic = MAGIC_NUMBER;
                


                return (void*)h+1;





            
            
           


             

             





        }


        walk = walk->next;


    }
    return NULL;





}