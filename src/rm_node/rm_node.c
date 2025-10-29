#include "blockchain.h"

/**
* @brief count number of node in the list.
* @param t_list* head: head of the linked list.
*        string_array* array: structure with a char**, containing the node id.
* @return return the number of node.
*/
t_list* rm_node(t_list* head, string_array* array)
{
    t_list* current = head;
    t_list* temp = NULL;

    int nid = my_atoi(array->array[2]);
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