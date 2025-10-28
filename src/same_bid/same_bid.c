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