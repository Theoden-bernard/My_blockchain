#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <assert.h>

#define OK 0
#define ERR_NO_MORE_RESSOURCES 1
#define ERR_NODE_ALREADY_EXIST 2
#define ERR_BLOCK_ALREADY_EXIST 3
#define ERR_NODE_NOT_FOUND 4
#define ERR_BLOCK_NOT_FOUND 5
#define ERR_COMMAND_NOT_FOUND 6

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
    char** array_block;      //array of block to check if exist                | ["B3", "B1", "B10", "B4"]
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
void print_error_message(int);
int my_strcmp(char*, char*);
void my_strcpy(char*, char*);
void free_array(string_array*);
void free_block_list(t_block*);
void free_linked_list(t_list*);
void free_sync(t_sync*);
char* my_itoa(int);
int my_atoi(char*);
int same_nid (t_list*, int);
int same_bid(t_block*, t_block*);