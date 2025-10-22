#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <assert.h>

int READLINE_READ_SIZE = 512;

typedef struct s_string_array
{
    int size;
    char** array;
} string_array;

typedef struct s_block {
    char* bid;             // block id
    struct s_block* next;  // next block
} t_block;

typedef struct s_list {
    int nid;                     // node id
    struct s_block* head_block;  // block head
    struct s_list* next;         // next node
} t_list;

typedef struct s_sync {
    int nbr_block;           //size of the array_block
    int nbr_block_ref;       //nbr of block reference
    int nbr_block_in_check;  //nbr of block in check
    char** array_block;      //array of block to check if exist                | [B3, B1, B10, B4]
    int* array_check_block;  //array to check if it exist, 1 if exist 0 if not | [0 , 0 , 0 , 0 ] 
}t_sync;

typedef struct s_param {
    char* str;
    t_list*(*func)(t_list*, string_array*);
    t_list*(*test)(t_list*, char*);
}t_param;

int my_strlen(char*);
void* secure_malloc(size_t);
void print_double_list(t_block*);
void my_strcpy(char*, char*);
