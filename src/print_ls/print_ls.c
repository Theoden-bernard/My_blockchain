#include "blockchain.h"

/**
* @brief print the element of a linked list.
* @param t_list* head: head of the linked list.
*        string_array* array: structure used in other functions.
* @return return the head of the linked list printed.
*/
t_list* print_ls(t_list* head, string_array* empty)
{
    (void) empty;
    t_list* current = head;

    while (current != NULL)
    {
        printf("%d", current->nid);
        printf("\n");
        current = current->next;
    }
    
    return head;
}