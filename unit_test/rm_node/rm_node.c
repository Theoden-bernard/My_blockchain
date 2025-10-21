#include "blockchain.h"

/**
* @summary count number of node in the list.
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