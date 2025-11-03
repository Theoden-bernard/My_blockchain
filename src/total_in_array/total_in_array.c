#include "blockchain.h"

/**
* @brief count the number of element in an array.
* @param t_sync* my_sync_struct: struct countaning the array.
* @return return the size of the array.
*/
int total_in_array(t_sync* my_sync_struct)
{

    int index = 0;
    int compt = 0;

    while (compt < my_sync_struct->nbr_block_ref)
    {
        index += my_sync_struct->array_check_block[compt];
        compt += 1;
    }

    return index;
}

#ifdef UNIT_TEST_TOTAL_IN_ARRAY
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

    if (total_in_array(sync_struct) == 4)
    {
        printf("True\n");
        return 1;
    }
    printf("False\n");
    return 0;
}
#endif