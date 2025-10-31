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

#ifdef UNIT_TEST_SAME_NID
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

    int nid = 2;
    
    if (same_nid(head, nid))
    {
        printf("True\n")
        return 1;
    }
    printf("False\n");
    return 0;
}
#endif