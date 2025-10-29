#include "blockchain.h"

int READLINE_READ_SIZE = 512;

/**
 * @brief create a buffer for readline using secure_malloc.
 * @return the buffer initialised.
 */
void* init_my_readline()
{
    void* buff = secure_malloc(sizeof(char) * READLINE_READ_SIZE);
    return buff;
}

#ifdef UNIT_TEST_INIT_MY_READLINE
int main()
{
    char* test = init_my_readline();
    if (test != NULL)
    {
        printf("True\n");
        return 1;
    }
    printf("False\n");
    return 0;
}
#endif