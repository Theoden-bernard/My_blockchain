#include <blockchain.h>

/**
* @brief recreation of strlen.
* @param char* string: array of character.
* @return return the size.
*/
int my_strlen(char* string)
{
    if (string == NULL)
    {
        return 1;
    }

    int size = 0;
    while (string[size] != '\0')
    {
        size += 1;
    }
    return size;
}

#ifdef UNIT_TEST
int main()
{
    char* test = "this is a test\n";
    if (my_strlen(test) == 15)
    {
        printf("True\n");
        return 1;
    }
    printf("False\n");
    return 0;
}
#endif