#include "blockchain.h"

/**
* @brief removes a block inside a linked list.
* @param t_block*: head: head of the linked list.
*        char* bid: id of the block to remove.
*        int nid: id of the node were the block list is.
* @return return the head once the block has been removed.
*/
t_block* remove_block(t_block* head, char* bid, int nid)
{
    t_block* current = head;
    t_block* temp = NULL;

    if (head == NULL)  // check if the linked list isn't NULL
    {
        print_error_message(ERR_BLOCK_NOT_FOUND);
        return head;
    }

    if (current->next == NULL)  // exception if the linked list only has one element
    {
        if (strcmp(current->bid, bid) != 0)  // if it's not the block that need to be removed
        {   
            if (nid != 0)
            {
                print_error_message(ERR_BLOCK_NOT_FOUND);
            }
            return head;            
        }
    
        free(head->next);
        head = NULL;
        return head;  // exactly like removing the only block
    }

    while (current->next != NULL && my_strcmp(current->next->bid, bid) != 0)  // search for the block to remove
    {
        current = current->next;
    }

    if (current->next == NULL)  // check if the block has been found
    {
        if (nid != -1)
        {
            print_error_message(ERR_BLOCK_NOT_FOUND);
        }
    
        return head;
    }

    temp = current->next;
    current->next = temp->next;
    free(temp);
    
    return head;
}

#ifdef UNIT_TEST_REMOVE_BLOCK
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

    head->head_block = remove_block(head->head_block, "1", 1);

    if (head->head_block->bid == NULL)
    {
        printf("True\n");
        return 1;
    }
    printf("False\n");
    return 0;
}
#endif