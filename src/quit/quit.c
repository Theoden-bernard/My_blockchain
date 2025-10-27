#include "blockchain.h"

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