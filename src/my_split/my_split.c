#include "blockchain.h"

string_array* my_split(char* string, char* separator)
{
    int size = 1;
    int index = 0;
    int temp_index = 0;
    int result_index = 0;
    int nb_occurence = (count_char(string, separator[0]) + 1);
    
    char* temp = secure_malloc(sizeof(char) * my_strlen(string));
    string_array* result = secure_malloc(sizeof(string_array));
    result->array = secure_malloc(sizeof(char *) * nb_occurence);
    result->size = 1;

    while (result_index < nb_occurence)  // initialisation of the array
    {
        while (string[temp_index] != separator[0] && string[temp_index] != '\0' && string[temp_index] != '\n')
        {
            size += 1;
            temp_index += 1;
        }

        result->array[result_index] = secure_malloc(sizeof(char) * size);
        temp_index += 1;
        result_index += 1;
        size = 1;
    }

    if (my_strcmp(string, "\0") == 0)
    {
        result->array[0] = "\0";
        return result;
    }

    if (nb_occurence == 1)
    {
        my_strcpy(string, result->array[0]);
        return result;
    }

    result_index = 0;
    temp_index = 0;
    while (string[index] != '\0' && string[index] != '\n')
    {
        if (string[index] != separator[0])
        {
            temp[temp_index] = string[index];
            temp_index += 1;
        }
        else {
            my_strcpy(temp, result->array[result_index]);
            result->size += 1;
            result_index += 1;
            temp_index = 0; 
            memset(temp, 0, sizeof(char) * my_strlen(temp));
        }
        index += 1;
    }
    my_strcpy(temp, result->array[result_index]);
    // free(string);    
    free(temp);
    return result;
}

#ifdef UNIT_TEST_MY_SPLIT
int main()
{
    string_array test = secure_malloc(sizeof(string_array*));

    test = my_split("this is a test", " ");

    if (my_strcmp(test->array[0], "this") == 0 && my_strcmp(test->array[0], "is") == 0 && my_strcmp(test->array[0], "a") == 0 && my_strcmp(test->array[0], "test") == 0)
    {
        printf("True\n");
        return 1;
    }
    printf("False\n");
    return 0;
}
#endif