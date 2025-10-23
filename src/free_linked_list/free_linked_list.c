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