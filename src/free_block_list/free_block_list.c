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

#ifdef UNIT_TEST_FREE_BLOCK_LIST
int main()
{
    t_block* head = secure_malloc(sizeof(t_block*));
    head->bid = secure_malloc(sizeof(char) * 4);
    head->next = secure_malloc(sizeof(t_block*));
    head->next->bid = secure_malloc(sizeof(char) * 4);
    head->next->next = NULL;

    free_block_list(head);

    printf("True\n");
    return 1;
}
#endif