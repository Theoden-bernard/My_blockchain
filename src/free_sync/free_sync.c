#include "blockchain.h"

/**
 * @brief free a structure of a t_sync type and all its elements.
 * @param t_sync* structure: structure to free.
 */
void free_sync(t_sync* structure)
{
    free(structure->array_block);
    free(structure->array_check_block);
    free(structure);
}

#ifdef UNIT_TEST_FREE_SYNC
int main()
{
    int index = 0;
    t_sync* test_sync = secure_malloc(sizeof(t_sync*));
    test_sync->array_check_block = secure_malloc(sizeof(int) * 20);
    test_sync->nbr_block = 25;
    test_sync->array_block = secure_malloc(sizeof(char*) * test_sync->nbr_block);

    while(index < test_sync->nbr_block)
    {
        test_sync->array_block[index] = secure_malloc(sizeof(char) * 10);
        index += 1;
    }

    free_sync(test_sync);

    printf("True\n");
    return 1;
}
#endif