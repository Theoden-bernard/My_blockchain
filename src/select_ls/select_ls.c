#include "blockchain.h"

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
    
    // print_error_message(ERR_COMMAND_NOT_FOUND);
    free_array(array);
    return head;
}