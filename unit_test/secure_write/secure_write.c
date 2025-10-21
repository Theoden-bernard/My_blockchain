#include <unistd.h>

/**
* @brief write something and verify the result.
* @param int fd: file descriptor.
*        const void* buff: array of character that will be writen.
*        size_t size: size of the array of character.
* @return return an int corresponding to the error.
*/
int secure_write(int fd, const void* buff, size_t size)
{
    int result = write(fd, buff, size);
    if (result == -1)
    {
        write(2, "Write failed\n", my_strlen("Write failed\n"));
        return -1;
    }
    return result;
}

#ifdef UNIT_TEST
int main()
{
    int fd = secure_open("README.md");
    assert(secure_write(fd, "test", my_strlen("test")) > 1);
}
#endif