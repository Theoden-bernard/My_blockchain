#include "blockchain.h"

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
    // print_error_message(ERR_COMMAND_NOT_FOUND);
    return head;
}