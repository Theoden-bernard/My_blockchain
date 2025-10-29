#include "blockchain.h"

/**
* @brief recreation of the function strcmp.
* @param char* string1 : first string that is compared.
*        char* string2 : second string that is compared:
* @return return 1 if the first one is superior, 0 if they are equals, -1 if the second one is superior.
*/
int my_strcmp(char* string1, char* string2)
{
    int index = 0;
    
    if (my_strlen(string1) < my_strlen(string2))
    {   
        return -1;
    }
    if (my_strlen(string1) > my_strlen(string2))
    {
        return 1;
    }
    while (string1[index] == string2[index] && string1[index] != '\0' && string2[index] != '\0')
    {
        index += 1;
    }
    if (string1[index] < string2[index])
    {
        return -1;
    }
    if (string1[index] > string2[index])
    {
        return 1;
    }
    return 0;
}

#ifdef UNIT_TEST_STRCMP
int main()
{
    char* test1 = "Test1";
    char* test2 = "Test";

    if (my_strcmp(test1, test2) == -1)
    {
        printf("True");
        return 1;
    }
}
#endif