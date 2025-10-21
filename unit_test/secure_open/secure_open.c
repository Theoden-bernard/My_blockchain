/**
* @brief open the file and verify the result.
* @param char* pathname: name of the path of the file.
*        int flags: flags or option for the open.
* @return return an int corresponding to the error.
*/
int secure_open(char* pathname, int flags)
{
    int result = open(pathname, flags);
    if (result == -1)
    {
        write(2, pathname, my_strlen(pathname));
        write(2, "Open failed\n", my_strlen("Open failed\n"));
        return -1;
    }
    return result;
}

#ifdef UNIT_TEST
int main()
{
    int fd = secure_open("README.md" | O_RDONLY);
    if (fd > -1)
    {
        return 1;
    }
    else return 0;
}
#endif