#include "blockchain.h"

/**
* @brief add a node in a linked list without printing anything.
* @param s_list* head: first elem of the linked list.
*        int id: id of the node.
* @return return the head of the linked list.
*/
t_list* add_node_duplicate(t_list* head, int id)
{
    t_list* current = head;
    
    if (current == NULL)
    {
        current = create_node(id);
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