char* my_itoa(int nbr)
{
    int save_nbr = nbr;
    char zero_in_char = 48;
    int size = 0;

    if (nbr == 0)
    {
        return "0";
    }
    
    while (nbr > 0)
    {
        nbr /= 10;
        size += 1;
    }

    if (nbr < 0) 
    {
        nbr = -1 * nbr;
        save_nbr = nbr;

        while (nbr > 0)
        {
            nbr /= 10;
            size += 1;
        }

        nbr = save_nbr;
        size += 1;
        char* nbr_in_to_char = secure_malloc(sizeof(char) * (size));

        while (nbr > 0)
        {
            zero_in_char += (nbr % 10);
            nbr_in_to_char[size -1] = zero_in_char;
            nbr /= 10;
            size -= 1;
            zero_in_char = 48;
        }
        
        nbr_in_to_char[0] = '-';

        return nbr_in_to_char;
    }

    char* nbr_in_to_char = secure_malloc(sizeof(char) * (size + 1));
    nbr = save_nbr;

    while (nbr > 0)
    {    
        zero_in_char += (nbr % 10);
        nbr_in_to_char[size - 1] = zero_in_char;
        nbr /= 10;
        size -= 1;
        zero_in_char = 48;
    }

    return nbr_in_to_char;
}