#include <stdio.h>

//********************************

#ifdef UNIT_TEST
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
#endif

//********************************

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

#ifdef UNIT_TEST
int main()
{
    char* test1 = "Test";
    char* test2 = "Test1";

    if (my_strcmp(test1, test2) == 1)
    {
        printf("Test 1: 1");
        return 1;
    }
    else{
        printf("TestADFAFAE");
        return 0;
    } 

    char* test3 = "abc";
    char* test4 = "ABC";

    if (my_strcmp(test1, test2) == -1)
    {
        printf("Test 1: -1");
        return 1;
    }
    else return 0;

    char* test5 = "toto";
    char* test6 = "toto";

    if (my_strcmp(test1, test2) == 0)
    {
        printf("Test 3: 0");
        return 1;
    }
    else return 0;
}
#endif