#include "blockchain.h"

/**
 * @brief go through a linked list and tell if a node has been found or not.
 * @param t_list* head: head of the linked list to go through.
 *        int id: id of the node to find.
 * @return return 1 if the nid is found, 0 if not.
 */
int same_nid (t_list* head, int id)
{
    int same_nid = 0;

    t_list* current = head;

    while (current != NULL && same_nid == 0) {
                        
        if (current->nid == id) 
        {
            same_nid = 1;
        }
        else {
            same_nid = 0;
        }

        current = current->next;
    }

    return same_nid;
}