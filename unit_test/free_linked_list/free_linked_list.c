#include "blockchain.h"

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