#include "blockchain.h"

/**
* @brief free every element of a structure.
* @param string_array* structure: structure to free.
*/
void free_array(string_array* structure)
{
    int index = 0;
    while (index < structure->size)
    {
        free(structure->array[index]);
        index += 1;
    }
    free(structure->array);
    free(structure);
}