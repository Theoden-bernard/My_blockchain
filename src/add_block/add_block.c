#include "blockchain.h"

#ifdef UNIT_TEST
/**
* @brief malloc the buffer and verify the result of the malloc.
* @param size_t size: size for the malloc.
* @return return the buffer that has been malloc.
*/
void* secure_malloc(size_t size)
{
    char* buff = malloc(size);
    if (buff == NULL)
    {
        // print_error_message(ERR_NO_MORE_RESSOURCES);
        write(1, "no more ressources available\n", 29);
        return NULL;
    }
    memset(buff, 0, size);
    return buff;
}
#endif

/**
* @brief add a new block to a given node.  
* @param t_list* head: head of the linked list.
*        string_array* array: contain the node id and the block id in different element of an array of string.
* @return return the modified head with the new block.
*/
t_list* add_block(t_list* head, string_array* array)
{
    t_list* current = head;
    
    char* bid = secure_malloc(sizeof(char) * my_strlen(array->array[2]));
    my_strcpy(array->array[2], bid);
    int nid = my_atoi(array->array[3]);

 
    if (nid == -1)  // if the nid is *
    {
        while (current != NULL)
        {
            current->head_block = new_block(current->head_block, bid, nid);
            current = current->next;
        }
        return head;
    }

    while (current != NULL && current->nid != nid)  // seach for the node
    {
        current = current->next;
    }

    if (current == NULL)  // check if the node exist
    {
        // print_error_message(ERR_NODE_NOT_FOUND); 
        return head;
    }

    current->head_block = new_block(current->head_block, bid, nid);

    if (current->head_block == NULL)  // check if new_block was succefull
    {
        return 0;
    }

    // print_error_message(OK);
    return head;
}

#ifdef UNIT_TEST_ADD_BLOCK
int main()
{
    t_list* head = secure_malloc(sizeof(t_list*));
    head->nid = 4;
    head->next = NULL;
}
#endif