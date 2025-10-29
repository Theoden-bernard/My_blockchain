#include "blockchain.h"

/**
* @brief print the element of a linked list.
* @param t_list* head: head of the linked list.
*        string_array* array: structure used in other functions.
* @return return the head of the linked list printed.
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

#ifdef UNIT_TEST_PRINT_LINKED_LIST
int main()
{
    t_list* head = secure_malloc(sizeof(t_list*));
    head->nid = 1;
    head->head_block = secure_malloc(sizeof(t_block*));
    head->head_block->bid = "1";
    head->head_block->next = NULL;
    head->next = secure_malloc(sizeof(t_list*));
    head->next->nid = 2;
    head->next->next = NULL;
}
#endif