#include "blockchain.h"

/**
* @summary print the element of a linked list.
* @param t_list* head: head of the linked list.
*        int print_block: int telling if the block of the nodes needs to be printed, 1 if yes, 0 if not.
*/
t_list* print_linked_list(t_list* head, string_array* empty)
{
    (void) empty;
    t_list* current = head;

    while (current != NULL)
    {
        printf("%d", current->nid);

        if (current->head_block != NULL)
        {
            printf(": ");
            print_double_list(current->head_block);
        }
        
        printf("\n");
        current = current->next;
    }

    return head;
}