#include "blockchain.h"

/**
 * @brief create a buffer for readline using secure_malloc.
 * @return the buffer initialised.
 */
void* init_my_readline()
{
    void* buff = secure_malloc(sizeof(char) * READLINE_READ_SIZE);
    return buff;
}