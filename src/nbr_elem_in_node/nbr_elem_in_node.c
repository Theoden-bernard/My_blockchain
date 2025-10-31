#include "blockchain.h"

/**
* @brief count the number of block in one node.
* @param t_list* head_block: head of block.
* @return return the number of block.
*/
int nbr_elem_in_node(t_block* head_block)
{
    int nbr = 0;
    t_block* current = head_block;

    while (current != NULL) {
        current = current->next;
        nbr += 1;
    }

    return nbr;
}

#ifdef UNIT_TEST_NBR_ELEM_IN_NODE
int main()
{
    t_list* head = secure_malloc(sizeof(t_list*));
    head->nid = 1;
    head->head_block = secure_malloc(sizeof(t_block*));
    head->head_block->bid = "1";
    head->head_block->next = secure_malloc(sizeof(t_block*));
    head->head_block->next->bid = "2";
    head->head_block->next->next = secure_malloc(sizeof(t_block*));
    head->head_block->next->next->bid = "3";
    head->head_block->next->next->next = NULL;
    head->next = NULL;

    if (nbr_elem_in_node(head->head_block) == 3)
    {
        printf("True\n");
        return 1;
    }
    printf("False\n");
    return 0;
}
#endif