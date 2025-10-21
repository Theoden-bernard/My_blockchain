#include <stdlib.h>
#include <string.h>

/**
* @brief copy a string into another.
* @param char* string: string that is copied.
*        char* result: where the string is copied.
*/
void my_strcpy(char* string, char* result)
{
    int index = 0;
    while (string[index] != '\0' && string[index] != '\n')
    {
        result[index] = string[index];
        index += 1;
    }
}

#ifdef UNIT_TEST
int main()
{
    char* string = malloc(sizeof(char) * 10);
    char* result = malloc(sizeof(char) * 10);
    string = "1234567890";
    my_strcpy(string, result);
    if (strcmp(string, result) == 0)
    {
        return 1;
    }
    return 0;
}
#endif