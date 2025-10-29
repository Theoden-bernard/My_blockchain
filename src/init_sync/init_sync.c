#include "blockchain.h"

/**
* @brief to initialise a sync struct.
* @param t_list* head: head of the linked list.
*        t_sync* my_sync_struct: struct sync to initiliase.
* @return return a sync struct.
*/
t_sync* init_sync_struct(t_list* head, t_sync* my_sync_struct)
{
    int index = 0;
    t_list* current = head;
    t_block* current_block = current->head_block;

    my_sync_struct = secure_malloc(sizeof(t_sync));
    my_sync_struct->nbr_block_ref = nbr_elem_in_node(head->head_block);
    my_sync_struct->array_block = secure_malloc(sizeof(char *) * nbr_elem_in_node(head->head_block));
    my_sync_struct->nbr_block_in_check = 0;
    my_sync_struct->nbr_block = 0;

    while (current_block != NULL) 
    {    
        my_sync_struct->array_block[index] = secure_malloc(sizeof(char) * strlen(current_block->bid));
        my_sync_struct->array_block[index] = current_block->bid;
        my_sync_struct->nbr_block += 1;
        
        index += 1;
        current_block = current_block->next;
    }
    
    my_sync_struct->array_check_block = secure_malloc(sizeof(int) * nbr_elem_in_node(head->head_block));

    return my_sync_struct;
}

#ifdef UNIT_TEST_INIT_SYNC
int main()
{
    t_list* head = secure_malloc(sizeof(t_list*));
    head->nid = 1;
    head->head_block = secure_malloc(sizeof(t_block*));
    head->head_block->bid = secure_malloc(sizeof(char) * 3);
    head->head_block->next = NULL;
    head->next = secure_malloc(sizeof(t_list*));
    head->next->nid = 2;
    head->next->next = NULL;

    t_sync* test = init_sync_struct(head, test);

    if (test != NULL)
    {
        printf("True\n");
        return 1;
    }
    printf("False\n");
    return 0;
}
#endif