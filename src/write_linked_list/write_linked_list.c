#include "blockchain.h"

/**
* @brief print the elements of a linked list.
* @param t_list* head: head of the linked list.
* @return return 0 if the function failed, else return 1.
*/
int write_linked_list(t_list* head, int fd)
{
    char* nid = NULL;
    t_list* current = head;
    while (current != NULL)
    {
        nid = my_itoa(current->nid);
        if (secure_write(fd, nid, my_strlen(nid)) == -1)
        {
            free(nid);
            return 0;
        }
        if (current->head_block != NULL)
        {
            if (secure_write(fd, ": ", 2) == -1)
            {
                free(nid);
                return 0;
            }
            if (write_double_list(current->head_block, fd) == 0)
            {
                free(nid);
                return 0;
            }
        }
        current = current->next;
        if (secure_write(fd, "\n", 1) == -1)
        {
            free(nid);
            return 0;
        }
        free(nid);
    }
    return 1;
}

#ifdef UNIT_TEST_WRITE_LINKED_LIST
int main()
{
    int fd = secure_open("savefile.txt");
    t_list* head = secure_malloc(sizeof(t_list*));
    head->nid = 1;
    head->head_block = secure_malloc(sizeof(t_block*));
    head->head_block->bid = "3";
    head->head_block->next = NULL;
    head->next = secure_malloc(sizeof(t_list*));
    head->next->nid = 2;
    head->next->next = NULL;

    if (write_linked_list(head, fd) == 1)
    {
        printf("True\n");
        return 1;
    }
    printf("False\n");
    return 0;
}
#endif