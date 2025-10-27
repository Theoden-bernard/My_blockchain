#include "blockchain.h"

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