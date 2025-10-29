#include "blockchain.h"

/**
 * @brief free every node of a linked list and the block list attached to it.
 * @param t_list* head: head of the linked list to free.
 */
void free_linked_list(t_list* head)
{
    t_list* temp = head;
    
    while (head != NULL)
    {
        temp = temp->next; 
        free_block_list(head->head_block);
        free(head);
        head = temp;
    }
}

#ifdef UNIT_TEST_FREE_LINKED_LIST
int main()
{
    t_list* head = secure_malloc(sizeof(t_list*));
    head->nid = 1;
    head->head_block = secure_malloc(sizeof(t_block*));
    head->head_block->bid = secure_malloc(sizeof(char) * 3);
    head->head_block->next = NULL;
    head->next = secure_malloc(sizeof(t_list*));
    head->next->nid = 2;
    head->next->next = NULL;

    free_linked_list(head);

    printf("True\n");
    return 1;
}
#endif