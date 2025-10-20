/**
* @brief add a node in a linked list.
* @param s_list* head: first elem of the linked list.
         string_array* array: array with the info of futur node.
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