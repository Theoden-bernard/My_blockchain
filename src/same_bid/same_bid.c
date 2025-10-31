#include "blockchain.h"

/**
* @brief compare 2 block list and see if they have the same bid in them. 
* @param t_block* current_block: the 1st list to compare.
*        t_block* temp_block: the 2nd list to compare.
* @return return an int, 1 if the block id of the lists are equals, 0 if not.
*/
int same_bid(t_block* current_block, t_block* temp_block)
{
    int same_bid = 0;

      while (current_block != NULL && same_bid == 0) {
                        
        if (my_strcmp(current_block->bid, temp_block->bid) == 0) 
        {
            same_bid = 1;
        }
        else {
            same_bid = 0;
        }

        current_block = current_block->next;
    }

    return same_bid;
}

#ifdef UNIT_TEST_SAME_BID
int main()
{
    t_list* head = secure_malloc(sizeof(t_list*));
    head->nid = 1;
    head->head_block = secure_malloc(sizeof(t_block*));
    head->head_block->bid = "1";
    head->head_block->next = NULL;
    head->next = secure_malloc(sizeof(t_list*));
    head->next->nid = 2;
    head->next->head_block = secure_malloc(sizeof(t_block*));
    head->head_block->next->bid = "1";
    head->next->next = NULL;

    if (same_bid(head->head_block, head->next->head_block))
    {
        printf("True\n");
        return 1;
    }
    printf("False\n");
    return 0;
}
#endif