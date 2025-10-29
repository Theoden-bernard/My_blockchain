#include "blockchain.h"

/**
* @brief free a structure of a string_array type and all its elements.
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

#ifdef UNIT_TEST_FREE_ARRAY
int main()
{
    int index = 0;
    string_array* test = secure_malloc(sizeof(string_array*));
    test->size = 10;
    test->array = secure_malloc(sizeof(char*) * test->size);
    while (index < test->size)
    {
        test->array[index] = secure_malloc(sizeof(char) * 25);
        index += 1;
    }

    free_array(test);

    printf("True\n");
    return 1;
}
#endif