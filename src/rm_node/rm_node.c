#include "blockchain.h"

/**
* @summary count number of node in the list.
* @param t_list* head_block: head of the list.
* @return return the number of node.
*/
t_list* rm_node(t_list* head, string_array* array)
{
    t_list* current = head;
    t_list* temp = NULL;

    // string_array* array = my_split(str, " ");
    int nid = my_atoi(array->array[2]);
    // free_array(array);
    if (nid == -1)
    {
        head = NULL;
        print_error_message(OK);
        return head;
    }

    if (current == NULL)  // if the head is NULL
    {
        print_error_message(ERR_NODE_NOT_FOUND);
        return head;
    }

    if (current->nid == nid)
    {
        head = head->next;
        print_error_message(OK);
        return head; 
    }

    while (current->next != NULL && current->next->nid != nid)  // searches for the node
    {
        current = current->next;
    }

    if (current->next == NULL)
    {
        print_error_message(ERR_NODE_NOT_FOUND);
        return head;
    }

    temp = current->next;
    current->next = temp->next;

    print_error_message(OK);
    
    free(temp);
    return head;
} 