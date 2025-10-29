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
    char* bid = array->array[2];
    int nid = my_atoi(array->array[3]);

    if (nid == -1)  // if the nid is *
    {
        while (current != NULL)
        {
            current->head_block = remove_block(current->head_block, bid, nid);
            current = current->next;
        }

        print_error_message(OK);
        return head;
    }

    while (current != NULL && current->nid != nid)  // search for the node
    {
        current = current->next;
    }

    if (current == NULL)  // check if the node exist
    {
        print_error_message(ERR_NODE_NOT_FOUND); 
        return head;
    }
    
    current->head_block = remove_block(current->head_block, bid, nid);

    print_error_message(OK);

    return head;
}

#ifdef UNIT_TEST_RM_BLOCK
int main()
{
    t_list* head = secure_malloc(sizeof(t_list*));
    head->nid = 1;
    head->head_block = secure_malloc(sizeof(t_block*));
    head->head_block->bid = "1";
    head->head_block->next = NULL;
    head->next = secure_malloc(sizeof(t_list*));
    head->next->nid = 2;
    head->next->next = NULL;

    string_array* test = secure_malloc(sizeof(string_array));
    test->array = secure_malloc(sizeof(char*) * 4);
    test->array[0] = "rm";
    test->array[1] = "block";
    test->array[2] = "1";
    test->array[3] = "1";
    test->size = 4;

    head = rm_block(head, test);

    if (head->head_block->bid == NULL)
    {
        printf("True\n");
        return 1;
    }
    printf("False\n");
    return 0;
}
#endif