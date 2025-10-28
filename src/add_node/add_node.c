#include "blockchain.h"

/**
* @brief create a node at the end of a linked list.
* @param int id: id of the created node.
* @return return the new node created.
*/
t_list* create_node(int id)
{
    t_list* new_node = secure_malloc(sizeof(t_list));
    
    if (new_node == NULL)
    {
        print_error_message(ERR_NO_MORE_RESSOURCES);
        free(new_node);
        return 0;
    }

    new_node->nid = id;
    new_node->next = NULL;

    return new_node;
}

/**
* @brief add a node in a linked list.
* @param t_list* head: head of the linked list.
*        string_array* array: array with the info of the node id.
* @return return the head of the linked list.
*/
t_list* add_node(t_list* head, string_array* array)
{
    t_list* current = head;
    int id = my_atoi(array->array[2]);
    if (current == NULL)
    {
        current = create_node(id);
        print_error_message(OK);
        return current;
    }

    while (current->next != NULL) 
    {
        current = current->next;
    }
    
    if (same_nid(head, id) == 0) 
    {
        current->next = create_node(id);
        print_error_message(OK);
    }
    else 
    {
        print_error_message(ERR_NODE_ALREADY_EXIST);
    }

    return head;
}