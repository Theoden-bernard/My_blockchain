  /**
* @summary check if the linked list is synced.
* @param t_list* head: head of the linked list.
* @return return 1 if the list is synced, 0 if not.
*/
int is_synced(t_list* head)
{
    if (head == NULL || nbr_node(head) == 1)
    {
        return 1;
    }

    t_list* current = head;
    int synced = 1;
    int index = 0;

    t_sync* my_sync_struct = NULL;
    my_sync_struct = init_sync_struct(current, my_sync_struct);

    current = current->next;

    t_block* current_block = current->head_block;

       while (current != NULL && synced == 1 ) {
        
        my_sync_struct = check_same_block(current_block, my_sync_struct);

           if (my_sync_struct->nbr_block_ref != my_sync_struct->nbr_block_in_check ) {
            synced = 0;
        }

        if (my_sync_struct->nbr_block_ref != total_in_array(my_sync_struct)) {
            synced = 0;
        }
        else 
        {
            while (index < my_sync_struct->nbr_block_ref) {
                my_sync_struct->array_check_block[index] = 0;
                index += 1;
            }
            my_sync_struct->nbr_block_in_check = 0;
            index = 0;
        }

        current = current->next;
        if (current != NULL) {
            current_block = current->head_block;
        }

    }

    free_sync(my_sync_struct);
    return synced;
}