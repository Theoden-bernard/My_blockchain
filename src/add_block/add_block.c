#include "blockchain.h"

/**
* @brief create a new block to the end of a block list.
* @param char* bid: id of the block to create. 
*        int nid: id of the node were the block list is rattached to.
* @return return the new node.
*/
t_block* new_block(t_block* head_block, char* bid, int nid)
{
    t_block* current = head_block;
    t_block* new_block = secure_malloc(sizeof(t_block));

    if (new_block == NULL)
    {
        print_error_message(ERR_NO_MORE_RESSOURCES);
        free(new_block);
        return head_block;
    }

     new_block->bid = bid;
    new_block->next = NULL;

    if (head_block == NULL)  // if no block has been initialised yet
    {
        return new_block;
    }

    if (same_bid(current, new_block) == 1)
    {   
        if (nid != -1)
        {
            print_error_message(ERR_BLOCK_ALREADY_EXIST);
        }
        free(new_block);
        return head_block;
    }

    while (current->next != NULL)
    {
        if (same_bid(current, new_block) == 1)
        {
            if (nid != -1)
            {
                print_error_message(ERR_BLOCK_ALREADY_EXIST);
            }
            free(new_block);
            return head_block;
        }
        current = current->next;
    }
    current->next = new_block;
    new_block->next = NULL;
    return head_block;
}

/**
* @brief add a new block to a given node.  
* @param t_list* head: head of the linked list.
*        string_array* array: contain the node id and the block id in different element of an array of string.
* @return return the modified head with the new block.
*/
t_list* add_block(t_list* head, string_array* array)
{
    t_list* current = head;
    
    char* bid = secure_malloc(sizeof(char) * my_strlen(array->array[2]));
    my_strcpy(array->array[2], bid);
    int nid = my_atoi(array->array[3]);

 
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

    print_error_message(OK);
    return head;
}

#ifdef UNIT_TEST
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
    else {
        free_linked_list(head);
        free_array(test);
        printf("False\n");
        return 0;
    }

}
#endif