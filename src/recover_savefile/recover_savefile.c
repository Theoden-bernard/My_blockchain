#include "blockchain.h"

/**
* @brief read the savefile and convert it back to a linked list.
* @param const char*: filename.
* @return return the head of the linked list.
*/
t_list* recover_savefile(char* filename)
{
    char* str_readline = NULL;
    t_list* head = NULL;
    int fd = open(filename, O_RDONLY);

    if (fd == -1)
    {
        return NULL;
    }
    
    while ((str_readline = my_readline(fd)) != NULL)
    {
        head = recover_linked_list(head, str_readline);
        free(str_readline);
    }
    
    close(fd);
    free(str_readline);

    return head;
}