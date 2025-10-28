#include "blockchain.h"

/**
 * @brief print an error message corresponding to the value of the error received.
 * @param int err: value of the error.
 */
void print_error_message(int err)
{
    if (err == OK) {  
        write(1, "OK\n", my_strlen("OK\n"));
    }
    if (err == ERR_NO_MORE_RESSOURCES) {  
        write(1, "1: no more resources available on the computer\n", my_strlen("1: no more resources available on the computer\n"));
    }
    if (err == ERR_NODE_ALREADY_EXIST) {  
        write(1, "2: this node already exists\n", my_strlen("2: this node already exists\n"));
    }
    if (err == ERR_BLOCK_ALREADY_EXIST) {  
        write(1, "3: this block already exists\n", my_strlen("3: this block already exists\n"));
    }
    if (err == ERR_NODE_NOT_FOUND) {  
        write(1, "4: node doesn't exist\n", my_strlen("4: node doesn't exist\n"));
    }
    if (err == ERR_BLOCK_NOT_FOUND) {  
        write(1, "5: block doesn't exist\n", my_strlen("5: block doesn't exist\n"));
    }
    if (err == ERR_COMMAND_NOT_FOUND) {  
        write(1, "6: command not found\n", my_strlen("6: command not found\n"));
    }
}