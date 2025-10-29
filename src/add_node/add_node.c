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
    int id = positive_atoi(array->array[2]);
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

#ifdef UNIT_TEST_ADD_NODE
int main()
{
    t_list* head = secure_malloc(sizeof(t_list*));
    head->nid = 1;
    head->next = NULL;

    string_array* test = secure_malloc(sizeof(string_array*));
    test->array = secure_malloc(sizeof(char*) * 3);
    test->array[0] = "add";
    test->array[1] = "node";
    test->array[2] = "2";
    test->size = 3;

    add_node(head, test);

    if (head->next->nid == 2)
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