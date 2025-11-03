#include "blockchain.h"

/**
* @brief search for the node id.
* @param char* string: string were the node id needs to be found.
* @return return the node id.
*/
char* find_node(char* string)
{
    char* result = secure_malloc(sizeof(char) * 100);
    int index = 0;
    int jndex = 0;
    int cpt = 0;
    while (string[index] != '\0')
    {
        if (cpt == 0)
        {
            result[jndex] = string[index];
            jndex += 1;
        }
        index += 1;
        if (string[index] == ' ' || string[index] == ':')
        {
            cpt += 1;
        }
    }
    return result;
}

#ifdef UNIT_TEST_FIND_NODE
int main()
{
    char* string = "1: 2 3";
    if (strcmp(find_node(string), "1") == 0)
    {
        printf("True\n");
        return 1;
    }
    printf("False\n");
    return 0;
}
#endif