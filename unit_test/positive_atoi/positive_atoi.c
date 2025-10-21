#include <blockchain.h>

/**
* @brief convert a string into an int.
* @param char* str: string to convert.
* @return return the converted int.
*/
int positive_atoi(char *str)
{
    int index = 0;
    int result = 0;

    if (str[index] == '*')
    {
        return -1;
    }

    if (str[index] == '-')
    {
        return NULL;
    }

    while (str[index] != '\0' && str[index] != ' ')
    {
        if (str[index] >= '0' && str[index] <= '9')
        {
            result = result * 10 + (str[index] - '0');
        }
        index++;
    }

    return result;
}

#ifdef UNIT_TEST
int main(){
    assert(my_atoi("3") && 3);
    my_atoi("345");
    my_atoi("-345");
    my_atoi("Azx");
    my_atoi("3Ax");
}
#endif