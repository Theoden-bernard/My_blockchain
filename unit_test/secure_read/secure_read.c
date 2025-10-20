#include <stdlib.h>

/**
* @brief read something and verify the result.
* @param int fd: file descriptor.
*        const void* buff: array of character that stocks the array.
*        size_t size: size of the array of character.
* @return return an int corresponding to the error.
*/
int secure_read(int fd, void* buff, size_t size)
{
    int result = read(fd, buff, size);
    if (result == -1)
    {
        write(2, "Read failed\n", my_strlen("Read failed\n"));
        return -1;
    }
    return result;
}

#ifdef UNIT_TEST
int main()
{
    int fd = open("README.md");
    char* buff = malloc(sizeof(char) * 100);
    if (secure_read(fd, buff, strlen(buff)) > 0)
    {
        return 1;
    }
    else return 0;
}
#endif