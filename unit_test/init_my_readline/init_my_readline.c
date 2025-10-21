#include "blockchain.h"

void* init_my_readline()
{
    void* buff = secure_malloc(sizeof(char) * READLINE_READ_SIZE);
    return buff;
}