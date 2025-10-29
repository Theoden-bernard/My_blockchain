#include "blockchain.h"

/**
* @brief count the number of node in the list.
* @param t_list* head_block: head of the list.
* @return return the number of node.
*/
int nbr_node(t_list* head)
{
    if (head == NULL) {
        return 0;
    }

    int index = 0;
    t_list* current = head;

    while (current != NULL) {
        index += 1;    
        current = current->next;
    }
    
    return index;
}

#ifdef UNIT_TEST_NBR_NODE
int main()
{
    t_list* head = secure_malloc(sizeof(t_list*));
    head->nid = 1;
    head->head_block = secure_malloc(sizeof(t_block*));
    head->next = secure_malloc(sizeof(t_list*));
    head->next->nid = 2;
    head->next->next = secure_malloc(sizeof(t_list*));
    head->next->next->nid = 3;
    head->next->next->next = NULL;
    
    if (nbr_node(head) == 3)
    {
        printf("True\n");
        return 1;
    }
    printf("False\n")
    return 0;
}
#endif