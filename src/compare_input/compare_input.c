#include "blockchain.h"

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

    // print_error_message(ERR_COMMAND_NOT_FOUND);  
    free_array(array);
    return head;
}