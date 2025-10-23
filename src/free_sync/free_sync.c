#include "blockchain.h"

void free_sync(t_sync* structure)
{
    free(structure->array_block);
    free(structure->array_check_block);
    free(structure);
}