#include "blockchain.h"

/**
* @brief add a new block to a given node without printing anything.  
* @param t_list* head: head of the linked list.
*        int nid: id of the node in the linked list.
*        char* bid: id to give to the new block.
* @return return the modified head with the new block.
*/
t_list* add_block_duplicate(t_list* head, char* bid, int nid)
{
    t_list* current = head;

      if (nid == -1)  // if the nid is *
    {
        while (current != NULL)
        {
            current->head_block = new_block(current->head_block, bid, nid);
            current = current->next;
        }
        return head;
    }

      while (current != NULL && current->nid != nid)  // seach for the node
    {
        current = current->next;
    }

      if (current == NULL)  // check if the node exist
    {
        print_error_message(ERR_NODE_NOT_FOUND);
        return head;
    }

      current->head_block = new_block(current->head_block, bid, nid);

      if (current->head_block == NULL)  // check if new_block was succefull
    {
        return 0;
    }
    return head;
}

#ifdef UNIT_TEST_ADD_BLOCK_DUPLICATE
int main()
{
    t_list* head = secure_malloc(sizeof(t_list*));
    head->nid = 1;
    head->next = NULL;
    
    string_array* test = secure_malloc(sizeof(string_array));
    test->array = secure_malloc(sizeof(char*) * 4);
    test->array[0] = "add";
    test->array[1] = "block";
    test->array[2] = "1";
    test->array[3] = "1";
    test->size = 4;

    add_block(head, test);

    if (my_strcmp(head->head_block->bid, "1") == 0)
    {
        free_linked_list(head);
        free_array(test);
        printf("True\n");
        return 1;
    }
    free_linked_list(head);
    free_array(test);
    printf("False\n");
    return 0;
}
#endif