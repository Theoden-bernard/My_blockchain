#include "blockchain.h"

/**
* @brief print the element of a linked list.
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

#ifdef UNIT_TEST_PRINT_DOUBLE_LIST
int main()
{
    t_block* head_block = secure_malloc(sizeof(t_block*));
    head_block->bid = "1";
    head_block->next = secure_malloc(sizeof(t_block*));
    head_block->next->bid = "2";
    head_block->next->next = secure_malloc(sizeof(t_block*));
    head_block->next->next->bid = "3";
    head_block->next->next->next = secure_malloc(sizeof(t_block*));
    head_block->next->next->next->next = NULL;

    print_double_list(head_block);

    printf("True\n");
    return 1;
}
#endif