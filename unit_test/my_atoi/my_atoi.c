/**
* @summary convert a string into an int.
* @param char* str: string to convert.
* @return return the converted int.
*/
int my_atoi(char *str)
{
    int index = 0;
    int result = 0;

    if (str[index] == '*')
    {
        return -1;
    }

    if (str[index] == '-')
    {
        exit(1);
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