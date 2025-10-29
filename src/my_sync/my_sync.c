#include "blockchain.h"

/**
* @brief to add all block in all node.
* @param t_list* head: it's just my linked list.
*        string_array* array: structure used in other functions.
* @return return my linked list.
*/
t_list* my_sync(t_list* head, char* empty){
    
    if (head == NULL)
    {
        // print_error_message(OK);
        return head;
    }

    (void)empty;
    t_list* current = head;
    t_list* temp = head;
    t_block* temp_block = head->head_block;
    t_block* current_block = temp_block;

    while (temp != NULL) {

        if (is_synced(head) == 1) 
        {
            // print_error_message(OK);
            return head;
        }

        if (temp_block == NULL)
        {
            current = head;
            temp = temp->next;
            temp_block = temp->head_block;
            current_block = current->head_block;
        }

        if (current == NULL)
        {
            if (temp_block != NULL) {
            
                temp_block = temp_block->next;

                if (temp_block != NULL) {
                    current = head;
                    current_block = current->head_block;
                }
         
                if (temp->next == NULL && temp_block == NULL) {
                    // print_error_message(OK);
                    return head;
                }

            }
        }
        else 
        {
            if (temp_block != NULL) 
            {
                if (same_bid(current_block, temp_block) != 1) 
                {    
                    if (current_block != NULL) {
                        while (current_block->next != NULL) {
                            current_block = current_block->next;
                        }
                    }
                    add_block_duplicate(head, temp_block->bid, current->nid);  // segfault quand temp_block est NULL
                }               
            }
            
            current = current->next;

            if (current != NULL) {
                current_block = current->head_block;
            }
        }
    }
    // print_error_message(OK);
    return head;
}

#ifdef UNIT_TEST_MY_SYNC
int main()
{
    t_list* head = secure_malloc(sizeof(t_list*));
    head->nid = 1;
    head->head_block = secure_malloc(sizeof(t_block*));
    head->head_block->bid = "3";
    head->head_block->next = NULL;
    head->next = secure_malloc(sizeof(t_list*));
    head->next->nid = 2;
    head->next->head_block = secure_malloc(sizeof(t_block*));
    head->next->head_block->bid = "1";
    head->next->next = NULL;

    head = my_sync(head, "");

    if (strcmp(head->head_block->bid->next, "1") == 0)
    {
        printf("True\n");
        return 1;
    }
    printf("False\n");
    return 0;
}
#endif