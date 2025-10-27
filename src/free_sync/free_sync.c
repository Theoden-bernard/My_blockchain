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