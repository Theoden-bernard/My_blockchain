#include "blockchain.h"

/**
* @summary print the element of a linked list.
* @param t_list* head: head of the linked list.
*/
void print_double_list(t_block* head)
{
    t_block* current = head;

    while (current->next != NULL)
    {
        printf("%s ", current->bid);
        current = current->next;
    }
    
    printf("%s", current->bid);
}