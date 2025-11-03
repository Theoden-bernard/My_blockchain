#include "blockchain.h"

/**
* @brief identify the block id once a space is encountered and stop when another one has been encountered.
* @param char* string: string were the block id needs to be found.
* @return return the block id.
*/
char* find_block(char* string)
{
    char* result = secure_malloc(sizeof(char) * 100);
    int index = 0;
    int jndex = 0;
    int cpt = 0;
    while (string[index] != '\0')
    {
        if (cpt == 1)
        {
            while (string[index] != ' ' && string[index] != '\0')
            {
                result[jndex] = string[index];
                index += 1;
                jndex += 1;
            }
        }
        if (string[index] == ' ')
        {
            cpt += 1;
        }
        index += 1;
    }
    return result;
}

#ifdef UNIT_TEST_FIND_BLOCK
int main()
{
    char* string = "1: 2 3";
    if (strcmp(find_block(string), "2") == 0)
    {
        printf("True\n");
        return 1;
    }
    printf("False\n");
    return 0;
}
#endif