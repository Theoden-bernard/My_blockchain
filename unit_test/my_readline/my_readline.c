#include "blockchain.h"

char* my_readline(int fd)
{
    if (fd == -1)
    {
        return NULL;
    }

    char buff = 0;
    char* result = init_my_readline();
    int index = 0;

    if (result == NULL)
    {
        return NULL;
    }

    while (read(fd, &buff, 1) != 0)
    {
        if (buff == '\n')
        {
            return result;
        }

        result[index] = buff;
        index += 1;
    }

    free(result);
    
    return NULL;
}