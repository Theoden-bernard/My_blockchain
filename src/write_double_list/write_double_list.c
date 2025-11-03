#include "blockchain.h"

/**
* @brief print the element of a linked list.
* @param t_list* head: head of the linked list.
* @return return 0 if the function failed, else return 1.
*/
int write_double_list(t_block* head, int fd)
{
    t_block* current = head;

      while (current->next != NULL)
    {
        if (secure_write(fd, current->bid, my_strlen(current->bid)) == -1)
        {
            return 0;
        }
        if (secure_write(fd, " ", 1) == -1)
        {
            return 0;
        }
        current = current->next;
    }
    if (secure_write(fd, current->bid, my_strlen(current->bid)) == -1)
    {
        return 0;
    }
    return 1;
}

#ifdef UNIT_TEST_WRITE_DOUBLE_LIST
int main()
{
    int fd = secure_open("savefile.txt");
    t_list* head = secure_malloc(sizeof(t_list*));
    head->head_block = secure_malloc(sizeof(t_block*));
    head->head_block->nid = "1";
    head->head_block->next = secure_malloc(sizeof(t_block*));
    head->head_block->next->nid = "2";
    head->head_block->next->next = secure_malloc(sizeof(t_block*));
    head->head_block->next->next->nid = "3";
    head->head_block->next->next->next = secure_malloc(sizeof(t_block*));
    head->head_block->next->next->next->nid = "4";
    head->head_block->next->next->next->next = NULL
    head->next = NULL;

    if (write_double_list(head, fd) == 1)
    {
        printf("True\n");
        return 1;
    }
    printf("False\n");
    return 0;

}
#endif