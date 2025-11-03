#include "blockchain.h"

/**
* @brief check is the blocks are the same.
* @param t_list* head: head of the block list.
*        t_sync* my_sync_struct: is my struct sync init.
* @return return a sync struct.
*/
t_sync* check_same_block(t_block* head, t_sync* my_sync_struct)
{
    t_block* current_block = head;
    int index = 0;
    int save_my_sync_struct_nbr_block_ref = my_sync_struct->nbr_block_ref;
    int compt = 0;
    
    while (current_block != NULL) 
    {   
        while (index < my_sync_struct->nbr_block_ref) 
        {
            if (my_strcmp(my_sync_struct->array_block[index], current_block->bid) == 0) 
            {
                my_sync_struct->array_check_block[index] += 1;
            }
            
            index += 1;
            compt += 1;
        }
        index = 0;
            
        current_block = current_block->next;
        my_sync_struct->nbr_block_in_check += 1;
    }
    my_sync_struct->nbr_block_ref = save_my_sync_struct_nbr_block_ref;
    return my_sync_struct;
}

#ifdef UNIT_TEST_CHECK_SAME_BLOCK
int main()
{
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
    t_sync* sync_struct = init_sync_struct(head, my_sync_struct);

    sync_struct = check_same_block(head, my_sync_struct);

    if (sync_struct != NULL)
    {
        printf("True\n");
        return 1;
    }
    printf("False\n");
    return 0;
}
#endif