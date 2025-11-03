#include "blockchain.h"

/**
 * @brief count the number of time a chracter is found in a string.
 * @param char* string: string to search in.
 *        char character: character to find in the string.
 * @return return the number characters found.
 */
int count_char(char* string, char character)
{
    int nb_char = 0;
    int index = 0;
    while (string[index] != '\0')
    {
        if (string[index] == character)
        {
            nb_char += 1;
        }
        index += 1;
    }
    return nb_char;
}

#ifdef UNIT_TEST_COUNT_CHAR
int main()
{
    char* string = "abcabcabc";
    char character = 'a';
    if (count_char(string, character) == 3)
    {
        printf("True\n");
        return 1;
    }
    printf("False\n");
    return 0;
}
#endif