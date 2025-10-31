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

/**
* @brief create a new block to the end of a block list.
* @param char* bid: id of the block to create. 
*        int nid: id of the node were the block list is rattached to.
* @return return the new node.
*/
t_block* new_block(t_block* head_block, char* bid, int nid)
{
    t_block* current = head_block;
    t_block* new_block = secure_malloc(sizeof(t_block));

    if (new_block == NULL)
    {
        print_error_message(ERR_NO_MORE_RESSOURCES);
        free(new_block);
        return head_block;
    }

    new_block->bid = bid;
    new_block->next = NULL;

    if (head_block == NULL)  // if no block has been initialised yet
    {
        return new_block;
    }

    if (same_bid(current, new_block) == 1)
    {   
        if (nid != -1)
        {
            print_error_message(ERR_BLOCK_ALREADY_EXIST);
        }
        free(new_block);
        return head_block;
    }

    while (current->next != NULL)
    {
        if (same_bid(current, new_block) == 1)
        {
            if (nid != -1)
            {
                print_error_message(ERR_BLOCK_ALREADY_EXIST);
            }
            free(new_block);
            return head_block;
        }
        current = current->next;
    }
    current->next = new_block;
    new_block->next = NULL;
    return head_block;
}

/**
* @brief add a new block to a given node.  
* @param t_list* head: head of the linked list.
*        string_array* array: contain the node id and the block id in different element of an array of string.
* @return return the modified head with the new block.
*/
t_list* add_block(t_list* head, string_array* array)
{
    t_list* current = head;
    
    char* bid = secure_malloc(sizeof(char) * my_strlen(array->array[2]));
    my_strcpy(array->array[2], bid);
    int nid = my_atoi(array->array[3]);

 
    if (nid == -1)  // if the nid is *
    {
        while (current != NULL)
        {
            current->head_block = new_block(current->head_block, bid, nid);
            current = current->next;
        }
        return head;
    }

    while (current != NULL && current->nid != nid)  // seach for the node
    {
        current = current->next;
    }

    if (current == NULL)  // check if the node exist
    {
        print_error_message(ERR_NODE_NOT_FOUND); 
        return head;
    }

    current->head_block = new_block(current->head_block, bid, nid);

    if (current->head_block == NULL)  // check if new_block was succefull
    {
        return 0;
    }

    print_error_message(OK);
    return head;
}

/**
 * @brief takes a string which is a part of the user input, to know the function to call.
 * @param t_list* head: head of the linked list that will be modified.
 *        char* input: string containing the user's input.
 * @return return the head of the list once modified.
 */
t_list* select_add(t_list* head, char* input)
{
    string_array* array = my_split(input, " ");

    t_param comutator[] =
    {
        {"node", add_node, 0},
        {"block", add_block, 0},
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

#ifdef UNIT_TEST_SELECT_ADD
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

    char* input = "add node 3";

    head = select_add(head, input);

    if (head->next->next->nid == 3)
    {
        printf("True\n");
        return 1;
    }
    printf("False\n");
    return 0;
}
#endif