#include "blockchain.h"

/**
* @brief removes a given block from the linked list.
* @param t_list* head: head of the linked list.
*        string_array* array: struct with a char**, containing the node id and the block id.
* @return return the modified head.
*/
t_list* rm_block(t_list* head, string_array* array)
{
    t_list* current = head;
    // string_array* array = secure_malloc(sizeof(string_array));
    // array = my_split(str, " ");
    char* bid = array->array[2];
    int nid = my_atoi(array->array[3]);

    if (nid == -1)  // if the nid is *
    {
        while (current != NULL)
        {
            current->head_block = remove_block(current->head_block, bid, nid);
            current = current->next;
        }

        // print_error_message(OK);
        // free_array(array);
        return head;
    }

    while (current != NULL && current->nid != nid)  // search for the node
    {
        current = current->next;
    }

    if (current == NULL)  // check if the node exist
    {
        // print_error_message(ERR_NODE_NOT_FOUND); 
        // free_array(array);
        return head;
    }
    
    current->head_block = remove_block(current->head_block, bid, nid);

    // print_error_message(OK);
    // free_array(array);

    return head;
}