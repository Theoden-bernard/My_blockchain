#include "blockchain.h"

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

#ifdef UNIT_TEST_SELECT_LS
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

    char* input = "ls -l";

    head = select_ls(head, input);
    
    printf("True\n");
    return 1;
}
#endif