#include "blockchain.h"

void free_block_list(t_block* head_block)
{
    
    t_block* tmp = head_block;
    
    while (head_block != NULL)
    {
        tmp = tmp->next;
        free(head_block->bid);
        free(head_block);
        head_block = tmp;
    }
}