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