#include "blockchain.h"
/**
* @brief malloc the buffer and verify the result of the malloc.
* @param size_t size: size for the malloc.
* @return return the buffer that has been malloc.
*/
void* secure_malloc(size_t size)
{
    char* buff = malloc(size);
    if (buff == NULL)
    {
        // print_error_message(ERR_NO_MORE_RESSOURCES);
        write(1, "no more ressources available\n", 29);
        return NULL;
    }
    memset(buff, 0, size);
    return buff;
}

#ifdef UNIT_TEST
int main()
{
    char* test = secure_malloc(2);
    if (test != NULL)
    {
        return 1;
    }
    else return 0;
}
#endif