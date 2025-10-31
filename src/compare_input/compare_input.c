#include "blockchain.h"

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

/**
* @brief to add all block in all node.
* @param t_list* head: it's just my linked list.
*        string_array* array: structure used in other functions.
* @return return my linked list.
*/
t_list* my_sync(t_list* head, char* empty){
    
    if (head == NULL)
    {
        print_error_message(OK);
        return head;
    }

    (void)empty;
    t_list* current = head;
    t_list* temp = head;
    t_block* temp_block = head->head_block;
    t_block* current_block = temp_block;

    while (temp != NULL) {

        if (is_synced(head) == 1) 
        {
            print_error_message(OK);
            return head;
        }

        if (temp_block == NULL)
        {
            current = head;
            temp = temp->next;
            temp_block = temp->head_block;
            current_block = current->head_block;
        }

        if (current == NULL)
        {
            if (temp_block != NULL) {
            
                temp_block = temp_block->next;

                if (temp_block != NULL) {
                    current = head;
                    current_block = current->head_block;
                }
         
                if (temp->next == NULL && temp_block == NULL) {
                    print_error_message(OK);
                    return head;
                }

            }
        }
        else 
        {
            if (temp_block != NULL) 
            {
                if (same_bid(current_block, temp_block) != 1) 
                {    
                    if (current_block != NULL) {
                        while (current_block->next != NULL) {
                            current_block = current_block->next;
                        }
                    }
                    add_block_duplicate(head, temp_block->bid, current->nid);
                }               
            }
            
            current = current->next;

            if (current != NULL) {
                current_block = current->head_block;
            }
        }
    }
    print_error_message(OK);
    return head;
}

/**
* @brief print the element of a linked list.
* @param t_list* head: head of the linked list.
*        string_array* array: structure used in other functions.
* @return return the head of the linked list printed.
*/
t_list* print_ls(t_list* head, string_array* empty)
{
    (void) empty;
    t_list* current = head;

    while (current != NULL)
    {
        printf("%d", current->nid);
        printf("\n");
        current = current->next;
    }
    
    return head;
}

/**
* @brief print the element of a linked list.
* @param t_list* head: head of the linked list.
*        string_array* array: structure used in other functions.
* @return return the head of the linked list printed.
*/
t_list* print_linked_list(t_list* head, string_array* empty)
{
    (void) empty;
    t_list* current = head;

    while (current != NULL)
    {
        printf("%d", current->nid);

        if (current->head_block != NULL)
        {
            printf(": ");
            print_double_list(current->head_block);
        }
        
        printf("\n");
        current = current->next;
    }

    return head;
}

/**
 * @brief takes a string which is a part of the user input, to know the function to call.
 * @param t_list* head: head of the linked list that will be modified.
 *        char* input: string containing the user's input.
 * @return return the head of the list once modified.
 */
t_list* select_ls(t_list* head, char* input)
{
    string_array* array = NULL;
    
    if (my_strcmp("ls\n", input) == 0) {
        array = my_split("empty ls", " ");
    }else {
        array = my_split(input, " ");
    }

    t_param comutator[] =
    {
        {"-l", print_linked_list, 0},
        {"ls", print_ls, 0},
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

/**
* @brief save the current linked list in a file and quit the program.
* @param t_list* head: head of the linked list to save.
*        char* string: string to know if the command quit was called or if the EOF was reached.
* @return return a modified head to tell the program to quit.
*/
t_list* quit(t_list* head, char* string)
{
    t_list* quit = secure_malloc(sizeof(t_list));
    quit->nid = -1;

    if (strcmp(string, "\0") == 0){
        return quit;
    }

    char* filename = "savefile.txt";
    remove(filename);
    int fd = secure_open(filename, O_WRONLY | O_CREAT);
    
    if (fd == -1)
    {
        return 0;
    }

    chmod(filename, 0777);

    if (write_linked_list(head, fd) == 0)
    {
        close(fd);
        return 0;
    }

    close(fd);
    free_linked_list(head);
    printf("Backing up blockchain...\n");

    return quit;
}

/**
 * @brief takes a string containing the input of the user, concatain every word into a char** and call the corresponding function.
 * @param char* input: string that is concatained and read from.
 *        t_list* head: head of the linked list to manipulate.
 * @return return the head once modified.
 */
void* compare_input(char* input, t_list* head)
{
    string_array* array = my_split(input, " ");
    
    t_param comutator[] =
    {
        {"add", 0, select_add},
        {"rm", 0, select_rm},
        {"sync", 0, my_sync},
        {"ls", 0, select_ls},
        {"quit", 0, quit},
        {"\0", 0, quit},
        {0,0,0}
    };

    t_param* tmp = comutator;

    while (tmp->str != 0) 
    {
        if (my_strcmp(tmp->str, array->array[0]) == 0) 
        {
            head = tmp->test(head, input);
            free_array(array);
            return head;
        }
        
        tmp += 1;
    }

    print_error_message(ERR_COMMAND_NOT_FOUND);  
    free_array(array);
    return head;
}

#ifdef UNIT_TEST_COMPARE_INPUT
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

    head = compare_input(input, head);

    if (head->next->next->nid == 3)
    {
        printf("True\n");
        return 1;
    }
    printf("False\n");
    return 0;
}
#endif