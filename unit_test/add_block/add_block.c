#include "blockchain.h"

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
        // print_error_message(ERR_NODE_NOT_FOUND); 
        return head;
    }

    current->head_block = new_block(current->head_block, bid, nid);

    if (current->head_block == NULL)  // check if new_block was succefull
    {
        return 0;
    }

    // print_error_message(OK);
    return head;
}