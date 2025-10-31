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

/**
 * @brief takes a string which is a part of the user input, to know the function to call.
 * @param t_list* head: head of the linked list that will be modified.
 *        char* input: string containing the user's input.
 * @return return the head of the list once modified.
 */
t_list* select_rm(t_list* head, char* input)
{
    string_array* array = my_split(input, " ");

    t_param comutator[] =
    {
        {"node", rm_node, 0},
        {"block", rm_block, 0},
        {0,0,0}
    };

    t_param* tmp = comutator;

    while (tmp->str != 0) 
    {
        if (my_strcmp(tmp->str, array->array[1]) == 0) 
        {
            head = tmp->func(head, array);
            free_array(array);
            return head;
        }
        
        tmp += 1;
    }
    
    free_array(array);
    print_error_message(ERR_COMMAND_NOT_FOUND);

    return head;
}

#ifdef UNIT_TEST_SELECT_RM
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

    char* input = "rm node 2";

    head = select_rm(head, input);

    if (head->next == NULL)
    {
        printf("True\n");
        return 1;
    }
    printf("False\n");
    return 0;
}
#endif