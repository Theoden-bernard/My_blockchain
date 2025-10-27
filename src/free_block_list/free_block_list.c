#include "blockchain.h"

/**
 * @brief free every element of a block list.
 * @param t_block* head_block: head of the block list.
 */
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