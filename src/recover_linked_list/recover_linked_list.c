#include "blockchain.h"

/**
* @brief read the line given and add the node and the eventual blocks.
* @param t_list* head: head of the linked list were the element are added.
*        char* str: line of character to read.
* @return return the modified head.
*/
t_list* recover_linked_list(t_list* head, char* str)
{
    t_list* current = head;
    char* tmp_id = NULL; //secure_malloc(sizeof(char) * 100);

    if (*str != '\0' && *str != '\n')  // identify the first character which coresponds to the node id 
    {
        tmp_id = find_node(str);
        head = add_node_duplicate(head, my_atoi(tmp_id));  // convert the char as an int
        current = head;
        str += my_strlen(tmp_id);  // go to the end of the node id
        memset(tmp_id, 0, 100);
        free(tmp_id);
    }

    if (head != NULL)
    {
        while (current->next != NULL)   // go to the node that has been added
        {
            current = current->next;
        }
    }

    if (*str != '\0' && *str != '\n')  // skip the character ':'
    {
        str += 1;
    }

    while (*str != '\0' && *str != '\n')  // go trough the rest of the string
    {
        tmp_id = find_block(str);
        head = add_block_duplicate(head, find_block(str), current->nid);  // add the block at the end of the block list
        str += my_strlen(tmp_id) + 1;  // go to the next block id 
        memset(tmp_id, 0, 100);
        free(tmp_id);
    }

    return head;
}

#ifdef UNIT_TEST_RECOVER_LINKED_LIST
int main()
{
    t_list* head = NULL;
    head = recover_linked_list(head, "1: 3 4\n");

    if (head != NULL)
    {
        printf("True\n");
        return 1;
    }
    printf("False\n");
    return 0;
}
#endif