#include "blockchain.h"

/**
* @brief add a node in a linked list without printing OK.
* @param s_list* head: first elem of the linked list.
*        int id: id of the node.
* @return return the head of the linked list.
*/
t_list* add_node_duplicate(t_list* head, int id)
{
    t_list* current = head;
    
    if (current == NULL)
    {
        current = create_node(id); // <------ to the future add elem at elem
        return current;
    }

      while (current->next != NULL) 
    {
        current = current->next;
    }
    
    if (same_nid(head, id) == 0) {
    
        current->next = create_node(id);
    }
    else {
        print_error_message(ERR_NODE_ALREADY_EXIST);
    }
    return head;
}

#ifdef UNIT_TEST_ADD_NODE_DUPLICATE
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