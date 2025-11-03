#include "blockchain.h"

int READLINE_READ_SIZE = 512;

/**
* ---------- SECURE MALLOC ----------
*/

/**
* @brief malloc the buffer and verify the result of the malloc.
* @param size_t size: size for the malloc.
* @return return the buffer that has been malloc.
*/
void* secure_malloc(size_t size)
{
    char* buff = malloc(size);
    if (buff == NULL)
    {
        // print_error_message(ERR_NO_MORE_RESSOURCES);
        write(1, "no more ressources available\n", 29);
        return NULL;
    }
    memset(buff, 0, size);
    return buff;
}

#ifdef UNIT_TEST_SECURE_MALLOC
int main()
{
    char* test = secure_malloc(2);
    if (test != NULL)
    {
        printf("True\n");
        return 1;
    }
    printf("False\n");
    return 0;
}
#endif

/**
* ---------- MY STRLEN ----------
*/

/**
* @brief recreation of strlen.
* @param char* string: array of character.
* @return return the size.
*/
int my_strlen(char* string)
{
    if (string == NULL)
    {
        return 1;
    }

    int size = 0;
    while (string[size] != '\0')
    {
        size += 1;
    }
    return size;
}

#ifdef UNIT_TEST_MY_STRLEN
int main()
{
    char* test = "this is a test\n";
    if (my_strlen(test) == 15)
    {
        printf("True\n");
        return 1;
    }
    printf("False\n");
    return 0;
}
#endif

/**
* ---------- SECURE OPEN ----------
*/

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

#ifdef UNIT_TEST_SECURE_OPEN
int main()
{
    int fd = secure_open("README.md" | O_RDONLY);
    if (fd > -1)
    {
        printf("True\n");
        return 1;
    }
    printf("False\n");
    return 0;
}
#endif

/**
* ---------- SECURE READ ----------
*/

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

#ifdef UNIT_TEST_SECURE_READ
int main()
{
    int fd = open("README.md");
    char* buff = malloc(sizeof(char) * 100);
    if (secure_read(fd, buff, strlen(buff)) > 0)
    {
        printf("True\n")
        return 1;
    }
    printf("False\n");
    return 0;
}
#endif

/**
* ---------- SECURE WRITE ----------
*/

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

#ifdef UNIT_TEST_SECURE_WRITE
int main()
{
    int fd = secure_open("README.md");
    if (secure_write(fd, "test", my_strlen("test")) > 1)
    {
        printf("True\n");
        return 1;
    }
    printf("False\n");
    return 0;
}
#endif

/**
* ---------- MY STRCMP ----------
*/

/**
* @brief recreation of the function strcmp.
* @param char* string1 : first string that is compared.
*        char* string2 : second string that is compared:
* @return return 1 if the first one is superior, 0 if they are equals, -1 if the second one is superior.
*/
int my_strcmp(char* string1, char* string2)
{
    int index = 0;
    
    if (my_strlen(string1) < my_strlen(string2))
    {   
        return -1;
    }
    if (my_strlen(string1) > my_strlen(string2))
    {
        return 1;
    }
    while (string1[index] == string2[index] && string1[index] != '\0' && string2[index] != '\0')
    {
        index += 1;
    }
    if (string1[index] < string2[index])
    {
        return -1;
    }
    if (string1[index] > string2[index])
    {
        return 1;
    }
    return 0;
}

#ifdef UNIT_TEST_STRCMP
int main()
{
    char* test1 = "Test1";
    char* test2 = "Test";

    if (my_strcmp(test1, test2) == -1)
    {
        printf("True");
        return 1;
    }
}
#endif

/**
* ---------- MY STRCPY ----------
*/

/**
* @brief copy a string into another.
* @param char* string: string that is copied.
*        char* result: where the string is copied.
*/
void my_strcpy(char* string, char* result)
{
    int index = 0;
    while (string[index] != '\0' && string[index] != '\n')
    {
        result[index] = string[index];
        index += 1;
    }
}

#ifdef UNIT_TEST_MY_STRCPY
int main()
{
    char* string = malloc(sizeof(char) * 10);
    char* result = malloc(sizeof(char) * 10);
    string = "1234567890";
    my_strcpy(string, result);
    if (strcmp(string, result) == 0)
    {
        printf("True\n");
        return 1;
    }
    printf("False\n");
    return 0;
}
#endif

/**
 * ---------- COUNT CHAR ----------
 */

/**
 * @brief count the number of time a chracter is found in a string.
 * @param char* string: string to search in.
 *        char character: character to find in the string.
 * @return return the number characters found.
 */
int count_char(char* string, char character)
{
    int nb_char = 0;
    int index = 0;
    while (string[index] != '\0')
    {
        if (string[index] == character)
        {
            nb_char += 1;
        }
        index += 1;
    }
    return nb_char;
}

#ifdef UNIT_TEST_COUNT_CHAR
int main()
{
    char* string = "abcabcabc";
    char character = 'a';
    if (count_char(string, character) == 3)
    {
        printf("True\n");
        return 1;
    }
    printf("False\n");
    return 0;
}
#endif

/**
* ---------- PRINT ERROR MESSAGE ----------
*/

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

#ifdef UNIT_TEST_PRINT_ERROR_MESSAGE
int main()
{
    print_error_message(OK);
    printf("True\n");
    return 1;
}
#endif

/**
* ---------- POSITIVE ITOA ----------
*/

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
        return 0;
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

#ifdef UNIT_TEST_POSITIVE_ATOI
int main()
{
    int test = positive_atoi("123");

    if (test = 123)
    {
        printf("True\n");
        return 1;
    }
    printf("False\n");
    return 0;
}
#endif

/**
* ---------- MY ITOA ----------
*/

/**
 * @brief converts an int into a string.
 * @param int nbr: number to convert as a string.
 * @return return the number once converted.
 */
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

#ifdef UNIT_TEST_MY_ITOA
int main()
{
    char* test = my_itoa(123);

    if (my_strcmp(test, "123") == 0)
    {
        printf("True\n");
        return 1;
    }
    printf("False\n")
    return 0;
}
#endif

/**
* ---------- NBR NODE ----------
*/

/**
* @brief count the number of node in the list.
* @param t_list* head_block: head of the list.
* @return return the number of node.
*/
int nbr_node(t_list* head)
{
    if (head == NULL) {
        return 0;
    }

    int index = 0;
    t_list* current = head;

    while (current != NULL) {
        index += 1;    
        current = current->next;
    }
    
    return index;
}

#ifdef UNIT_TEST_NBR_NODE
int main()
{
    t_list* head = secure_malloc(sizeof(t_list*));
    head->nid = 1;
    head->head_block = secure_malloc(sizeof(t_block*));
    head->next = secure_malloc(sizeof(t_list*));
    head->next->nid = 2;
    head->next->next = secure_malloc(sizeof(t_list*));
    head->next->next->nid = 3;
    head->next->next->next = NULL;
    
    if (nbr_node(head) == 3)
    {
        printf("True\n");
        return 1;
    }
    printf("False\n")
    return 0;
}
#endif

/**
* ---------- PRINT DOUBLE LIST ----------
*/

/**
* @brief print the element of a linked list.
* @param t_list* head: head of the linked list.
*/
void print_double_list(t_block* head)
{
    t_block* current = head;

    while (current->next != NULL)
    {
        printf("%s ", current->bid);
        current = current->next;
    }
    printf("%s", current->bid);
}

#ifdef UNIT_TEST_PRINT_DOUBLE_LIST
int main()
{
    t_block* head_block = secure_malloc(sizeof(t_block*));
    head_block->bid = "1";
    head_block->next = secure_malloc(sizeof(t_block*));
    head_block->next->bid = "2";
    head_block->next->next = secure_malloc(sizeof(t_block*));
    head_block->next->next->bid = "3";
    head_block->next->next->next = secure_malloc(sizeof(t_block*));
    head_block->next->next->next->next = NULL;

    print_double_list(head_block);

    printf("True\n");
    return 1;
}
#endif

/**
* ---------- PRINT LINKED LIST ----------
*/

/**
* @brief print the element of a linked list.
* @param t_list* head: head of the linked list.
*        string_array* array: structure used in other functions.
* @return return the head of the linked list printed.
*/
t_list* print_linked_list(t_list* head, string_array* empty)
{
    (void) empty;
    t_list* current = head;

    while (current != NULL)
    {
        printf("%d", current->nid);

        if (current->head_block != NULL)
        {
            printf(": ");
            print_double_list(current->head_block);
        }
        
        printf("\n");
        current = current->next;
    }

    return head;
}

#ifdef UNIT_TEST_PRINT_LINKED_LIST
int main()
{
    t_list* head = secure_malloc(sizeof(t_list*));
    head->nid = 1;
    head->head_block = secure_malloc(sizeof(t_block*));
    head->head_block->bid = "1";
    head->head_block->next = NULL;
    head->next = secure_malloc(sizeof(t_list*));
    head->next->nid = 2;
    head->next->next = NULL;

    print_linked_list(head, "");

    printf("True\n");
    return 1;
}
#endif

/**
* ---------- PRINT LS ----------
*/

/**
* @brief print the element of a linked list.
* @param t_list* head: head of the linked list.
*        string_array* array: structure used in other functions.
* @return return the head of the linked list printed.
*/
t_list* print_ls(t_list* head, string_array* empty)
{
    (void) empty;
    t_list* current = head;

    while (current != NULL)
    {
        printf("%d", current->nid);
        printf("\n");
        current = current->next;
    }
    
    return head;
}

#ifdef UNIT_TEST_PRINT_LS
int main()
{
    t_list* head = secure_malloc(sizeof(t_list*));
    head->nid = 1;
    head->head_block = secure_malloc(sizeof(t_block*));
    head->head_block->bid = "1";
    head->head_block->next = NULL;
    head->next = secure_malloc(sizeof(t_list*));
    head->next->nid = 2;
    head->next->next = NULL;

    print_ls(head);

    printf("True\n");
    return 1;
}
#endif

/**
* ---------- FREE ARRAY ----------
*/

/**
* @brief free a structure of a string_array type and all its elements.
* @param string_array* structure: structure to free.
*/
void free_array(string_array* structure)
{
    int index = 0;
    while (index < structure->size)
    {
        free(structure->array[index]);
        index += 1;
    }
    free(structure->array);
    free(structure);
}

#ifdef UNIT_TEST_FREE_ARRAY
int main()
{
    int index = 0;
    string_array* test = secure_malloc(sizeof(string_array*));
    test->size = 10;
    test->array = secure_malloc(sizeof(char*) * test->size);
    while (index < test->size)
    {
        test->array[index] = secure_malloc(sizeof(char) * 25);
        index += 1;
    }

    free_array(test);

    printf("True\n");
    return 1;
}
#endif

/**
* ---------- FREE BLOCK LIST ----------
*/

/**
 * @brief free every element of a block list.
 * @param t_block* head_block: head of the block list.
 */
void free_block_list(t_block* head_block)
{
    t_block* tmp = head_block;
    
    while (head_block != NULL)
    {
        tmp = tmp->next;
        free(head_block->bid);
        free(head_block);
        head_block = tmp;
    }
}

#ifdef UNIT_TEST_FREE_BLOCK_LIST
int main()
{
    t_block* head = secure_malloc(sizeof(t_block*));
    head->bid = secure_malloc(sizeof(char) * 4);
    head->next = secure_malloc(sizeof(t_block*));
    head->next->bid = secure_malloc(sizeof(char) * 4);
    head->next->next = NULL;

    free_block_list(head);

    printf("True\n");
    return 1;
}
#endif

/**
* ---------- FREE LINKED LIST ----------
*/

/**
 * @brief free every node of a linked list and the block list attached to it.
 * @param t_list* head: head of the linked list to free.
 */
void free_linked_list(t_list* head)
{
    t_list* temp = head;
    
    while (head != NULL)
    {
        temp = temp->next; 
        free_block_list(head->head_block);
        free(head);
        head = temp;
    }
}

#ifdef UNIT_TEST_FREE_LINKED_LIST
int main()
{
    t_list* head = secure_malloc(sizeof(t_list*));
    head->nid = 1;
    head->head_block = secure_malloc(sizeof(t_block*));
    head->head_block->bid = secure_malloc(sizeof(char) * 3);
    head->head_block->next = NULL;
    head->next = secure_malloc(sizeof(t_list*));
    head->next->nid = 2;
    head->next->next = NULL;

    free_linked_list(head);

    printf("True\n");
    return 1;
}
#endif

/**
* ---------- FREE SYNC ----------
*/

/**
 * @brief free a structure of a t_sync type and all its elements.
 * @param t_sync* structure: structure to free.
 */
void free_sync(t_sync* structure)
{
    free(structure->array_block);
    free(structure->array_check_block);
    free(structure);
}

#ifdef UNIT_TEST_FREE_SYNC
int main()
{
    int index = 0;
    t_sync* test_sync = secure_malloc(sizeof(t_sync*));
    test_sync->array_check_block = secure_malloc(sizeof(int) * 20);
    test_sync->nbr_block = 25;
    test_sync->array_block = secure_malloc(sizeof(char*) * test_sync->nbr_block);

    while(index < test_sync->nbr_block)
    {
        test_sync->array_block[index] = secure_malloc(sizeof(char) * 10);
        index += 1;
    }

    free_sync(test_sync);

    printf("True\n");
    return 1;
}
#endif

/**
* ---------- MY SPLIT ----------
*/

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

/**
* ---------- SAME BID ----------
*/

/**
* @brief compare 2 block list and see if they have the same bid in them. 
* @param t_block* current_block: the 1st list to compare.
*        t_block* temp_block: the 2nd list to compare.
* @return return an int, 1 if the block id of the lists are equals, 0 if not.
*/
int same_bid(t_block* current_block, t_block* temp_block)
{
    int same_bid = 0;

      while (current_block != NULL && same_bid == 0) {
                        
        if (my_strcmp(current_block->bid, temp_block->bid) == 0) 
        {
            same_bid = 1;
        }
        else {
            same_bid = 0;
        }

        current_block = current_block->next;
    }

    return same_bid;
}

#ifdef UNIT_TEST_SAME_BID
int main()
{
    t_list* head = secure_malloc(sizeof(t_list*));
    head->nid = 1;
    head->head_block = secure_malloc(sizeof(t_block*));
    head->head_block->bid = "1";
    head->head_block->next = NULL;
    head->next = secure_malloc(sizeof(t_list*));
    head->next->nid = 2;
    head->next->head_block = secure_malloc(sizeof(t_block*));
    head->head_block->next->bid = "1";
    head->next->next = NULL;

    if (same_bid(head->head_block, head->next->head_block))
    {
        printf("True\n");
        return 1;
    }
    printf("False\n");
    return 0;
}
#endif

/**
* ---------- SAME NID ----------
*/

/**
 * @brief go through a linked list and tell if a node has been found or not.
 * @param t_list* head: head of the linked list to go through.
 *        int id: id of the node to find.
 * @return return 1 if the nid is found, 0 if not.
 */
int same_nid (t_list* head, int id)
{
    int same_nid = 0;

    t_list* current = head;

    while (current != NULL && same_nid == 0) {
                        
        if (current->nid == id) 
        {
            same_nid = 1;
        }
        else {
            same_nid = 0;
        }

        current = current->next;
    }

    return same_nid;
}

#ifdef UNIT_TEST_SAME_NID
int main()
{
    t_list* head = secure_malloc(sizeof(t_list*));
    head->nid = 1;
    head->head_block = secure_malloc(sizeof(t_block*));
    head->head_block->bid = "1";
    head->head_block->next = NULL;
    head->next = secure_malloc(sizeof(t_list*));
    head->next->nid = 2;
    head->next->next = NULL;

    int nid = 2;
    
    if (same_nid(head, nid))
    {
        printf("True\n")
        return 1;
    }
    printf("False\n");
    return 0;
}
#endif

/**
* ---------- NBR ELEM IN NODE ----------
*/

/**
* @brief count the number of block in one node.
* @param t_list* head_block: head of block.
* @return return the number of block.
*/
int nbr_elem_in_node(t_block* head_block)
{
    int nbr = 0;
    t_block* current = head_block;

    while (current != NULL) {
        current = current->next;
        nbr += 1;
    }

    return nbr;
}

#ifdef UNIT_TEST_NBR_ELEM_IN_NODE
int main()
{
    t_list* head = secure_malloc(sizeof(t_list*));
    head->nid = 1;
    head->head_block = secure_malloc(sizeof(t_block*));
    head->head_block->bid = "1";
    head->head_block->next = secure_malloc(sizeof(t_block*));
    head->head_block->next->bid = "2";
    head->head_block->next->next = secure_malloc(sizeof(t_block*));
    head->head_block->next->next->bid = "3";
    head->head_block->next->next->next = NULL;
    head->next = NULL;

    if (nbr_elem_in_node(head->head_block) == 3)
    {
        printf("True\n");
        return 1;
    }
    printf("False\n");
    return 0;
}
#endif

/**
* ---------- CHECK SAME BLOCK ----------
*/

t_sync* check_same_block(t_block* head, t_sync* my_sync_struct)
{
    t_block* current_block = head;
    int index = 0;
    int save_my_sync_struct_nbr_block_ref = my_sync_struct->nbr_block_ref;
    
    while (current_block != NULL) 
    {   
        while (index < my_sync_struct->nbr_block_ref) 
        {
            if (my_strcmp(my_sync_struct->array_block[index], current_block->bid) == 0) 
            {
                my_sync_struct->array_check_block[index] += 1;
            }
            
            index += 1;
        }
        index = 0;
            
        current_block = current_block->next;
        my_sync_struct->nbr_block_in_check += 1;
    }
    my_sync_struct->nbr_block_ref = save_my_sync_struct_nbr_block_ref;
    return my_sync_struct;
}

#ifdef UNIT_TEST_CHECK_SAME_BLOCK
int main()
{
    t_list* head = secure_malloc(sizeof(t_list*));
    head->head_block = secure_malloc(sizeof(t_block*));
    head->head_block->nid = "1";
    head->head_block->next = secure_malloc(sizeof(t_block*));
    head->head_block->next->nid = "2";
    head->head_block->next->next = secure_malloc(sizeof(t_block*));
    head->head_block->next->next->nid = "3";
    head->head_block->next->next->next = secure_malloc(sizeof(t_block*));
    head->head_block->next->next->next->nid = "4";
    head->head_block->next->next->next->next = NULL
    head->next = NULL;
    t_sync* sync_struct = init_sync_struct(head, my_sync_struct);

    sync_struct = check_same_block(head, my_sync_struct);

    if (sync_struct != NULL)
    {
        printf("True\n");
        return 1;
    }
    printf("False\n");
    return 0;
}
#endif

/**
* ---------- INIT MY READLINE ----------
*/

/**
 * @brief create a buffer for readline using secure_malloc.
 * @return the buffer initialised.
 */
void* init_my_readline()
{
    void* buff = secure_malloc(sizeof(char) * READLINE_READ_SIZE);
    return buff;
}

#ifdef UNIT_TEST_INIT_MY_READLINE
int main()
{
    char* test = init_my_readline();
    if (test != NULL)
    {
        printf("True\n");
        return 1;
    }
    printf("False\n");
    return 0;
}
#endif

/**
* ---------- MY READLINE ----------
*/

/**
 * @brief read the content of a file until a '\n' or the end of the file is encountered.
 * @param int fd: file descriptor of the file were the content.
 * @return return a string with the content that was read.
 */
char* my_readline(int fd)
{
    if (fd == -1)
    {
        return NULL;
    }

    char buff = 0;
    char* result = init_my_readline();
    int index = 0;

    if (result == NULL)
    {
        return NULL;
    }

    while (read(fd, &buff, 1) != 0)
    {
        if (buff == '\n')
        {
            return result;
        }

        result[index] = buff;
        index += 1;
    }

    free(result);
    
    return NULL;
}

#ifdef UNIT_TEST_MY_READLINE
int main()
{
    int fd = open("./src/my_readline/my_readline.c");
    char* test = my_readline(fd);

    if (test != NULL)
    {
        printf("True\n");
        return 1;
    }
    printf("False\n");
    return 0;
}
#endif

/**
* ---------- INIT SYNC ----------
*/

/**
* @brief to initialise a sync struct.
* @param t_list* head: head of the linked list.
*        t_sync* my_sync_struct: struct sync to initiliase.
* @return return a sync struct.
*/
t_sync* init_sync_struct(t_list* head, t_sync* my_sync_struct)
{
    int index = 0;
    t_list* current = head;
    t_block* current_block = current->head_block;

    my_sync_struct = secure_malloc(sizeof(t_sync));
    my_sync_struct->nbr_block_ref = nbr_elem_in_node(head->head_block);
    my_sync_struct->array_block = secure_malloc(sizeof(char *) * nbr_elem_in_node(head->head_block));
    my_sync_struct->nbr_block_in_check = 0;
    my_sync_struct->nbr_block = 0;

    while (current_block != NULL) 
    {    
        my_sync_struct->array_block[index] = secure_malloc(sizeof(char) * strlen(current_block->bid));
        my_sync_struct->array_block[index] = current_block->bid;
        my_sync_struct->nbr_block += 1;
        
        index += 1;
        current_block = current_block->next;
    }
    
    my_sync_struct->array_check_block = secure_malloc(sizeof(int) * nbr_elem_in_node(head->head_block));

    return my_sync_struct;
}

#ifdef UNIT_TEST_INIT_SYNC
int main()
{
    t_list* head = secure_malloc(sizeof(t_list*));
    head->nid = 1;
    head->head_block = secure_malloc(sizeof(t_block*));
    head->head_block->bid = secure_malloc(sizeof(char) * 3);
    head->head_block->next = NULL;
    head->next = secure_malloc(sizeof(t_list*));
    head->next->nid = 2;
    head->next->next = NULL;

    t_sync* test = init_sync_struct(head, test);

    if (test != NULL)
    {
        printf("True\n");
        return 1;
    }
    printf("False\n");
    return 0;
}
#endif

/**
* ---------- IS SYNCED ----------
*/

/**
* @brief check if the linked list is synced.
* @param t_list* head: head of the linked list.
* @return return 1 if the list is synced, 0 if not.
*/
int is_synced(t_list* head)
{
    if (head == NULL || nbr_node(head) == 1)
    {
        return 1;
    }

    t_list* current = head;
    int synced = 1;
    int index = 0;

    t_sync* my_sync_struct = NULL;
    my_sync_struct = init_sync_struct(current, my_sync_struct);

    current = current->next;

    t_block* current_block = current->head_block;

       while (current != NULL && synced == 1 ) {
        
        my_sync_struct = check_same_block(current_block, my_sync_struct);

           if (my_sync_struct->nbr_block_ref != my_sync_struct->nbr_block_in_check ) {
            synced = 0;
        }

        if (my_sync_struct->nbr_block_ref != total_in_array(my_sync_struct)) {
            synced = 0;
        }
        else 
        {
            while (index < my_sync_struct->nbr_block_ref) {
                my_sync_struct->array_check_block[index] = 0;
                index += 1;
            }
            my_sync_struct->nbr_block_in_check = 0;
            index = 0;
        }

        current = current->next;
        if (current != NULL) {
            current_block = current->head_block;
        }

    }

    free_sync(my_sync_struct);
    return synced;
}

#ifdef UNIT_TEST_IS_SYNCED
int main()
{
    t_list* head = secure_malloc(sizeof(t_list*));
    head->nid = 1;
    head->head_block = secure_malloc(sizeof(t_block*));
    head->head_block->bid = "1";
    head->head_block->next = NULL;
    head->next = secure_malloc(sizeof(t_list*));
    head->next->nid = 2;
    head->next->head_block = secure_malloc(sizeof(t_block*));
    head->next->head_block->bid = "1";
    head->next->next = NULL;

    if (is_synced(head))
    {
        printf("True\n");
        return 1;
    }
    printf("False\n");
    return 0;
}
#endif

/**
* ---------- TOTAL IN ARRAY ----------
*/

/**
* @brief count the number of element in an array.
* @param t_sync* my_sync_struct: struct countaning the array.
* @return return the size of the array.
*/
int total_in_array(t_sync* my_sync_struct)
{

    int index = 0;
    int compt = 0;

    while (compt < my_sync_struct->nbr_block_ref)
    {
        index += my_sync_struct->array_check_block[compt];
        compt += 1;
    }

    return index;
}

#ifdef UNIT_TEST_TOTAL_IN_ARRAY
int main()
{
    t_list* head = secure_malloc(sizeof(t_list*));
    head->head_block = secure_malloc(sizeof(t_block*));
    head->head_block->nid = "1";
    head->head_block->next = secure_malloc(sizeof(t_block*));
    head->head_block->next->nid = "2";
    head->head_block->next->next = secure_malloc(sizeof(t_block*));
    head->head_block->next->next->nid = "3";
    head->head_block->next->next->next = secure_malloc(sizeof(t_block*));
    head->head_block->next->next->next->nid = "4";
    head->head_block->next->next->next->next = NULL
    head->next = NULL;
    t_sync* sync_struct = init_sync_struct(head, my_sync_struct);

    if (total_in_array(sync_struct) == 4)
    {
        printf("True\n");
        return 1;
    }
    printf("False\n");
    return 0;
}
#endif

/**
* ---------- RECOVER LINKED LIST ----------
*/

/**
* @brief read the line given and add the node and the eventual blocks.
* @param t_list* head: head of the linked list were the element are added.
*        char* str: line of character to read.
* @return return the modified head.
*/
t_list* recover_linked_list(t_list* head, char* str)
{
    t_list* current = head;
    char* tmp_id = NULL; //secure_malloc(sizeof(char) * 100);

    if (*str != '\0' && *str != '\n')  // identify the first character which coresponds to the node id 
    {
        tmp_id = find_node(str);
        head = add_node_duplicate(head, positive_atoi(tmp_id));  // convert the char as an int
        current = head;
        str += my_strlen(tmp_id);  // go to the end of the node id
        memset(tmp_id, 0, 100);
        free(tmp_id);
    }

    if (head != NULL)
    {
        while (current->next != NULL)   // go to the node that has been added
        {
            current = current->next;
        }
    }

    if (*str != '\0' && *str != '\n')  // skip the character ':'
    {
        str += 1;
    }

    while (*str != '\0' && *str != '\n')  // go trough the rest of the string
    {
        tmp_id = find_block(str);
        head = add_block_duplicate(head, find_block(str), current->nid);  // add the block at the end of the block list
        str += my_strlen(tmp_id) + 1;  // go to the next block id 
        memset(tmp_id, 0, 100);
        free(tmp_id);
    }

    return head;
}

#ifdef UNIT_TEST_RECOVER_LINKED_LIST
int main()
{
    t_list* head = NULL;
    head = recover_linked_list(head, "1: 3 4\n");

    if (head != NULL)
    {
        printf("True\n");
        return 1;
    }
    printf("False\n");
    return 0;
}
#endif

/**
* ---------- RECOVER SAVEFILE ----------
*/

/**
* @brief read the savefile and convert it back to a linked list.
* @param const char*: filename.
* @return return the head of the linked list.
*/
t_list* recover_savefile(char* filename)
{
    char* str_readline = NULL;
    t_list* head = NULL;
    int fd = open(filename, O_RDONLY);

    if (fd == -1)
    {
        return NULL;
    }
    
    while ((str_readline = my_readline(fd)) != NULL)
    {
        head = recover_linked_list(head, str_readline);
        free(str_readline);
    }
    
    close(fd);
    free(str_readline);

    return head;
}

#ifdef UNIT_TEST_RECOVER_SAVEFILE
int main()
{
    head = recover_savefile("Savefile.txt");
    if (head != NULL)
    {
        printf("True\n");
        return 1;
    }
    printf("False\n");
    return 0;
}
#endif

/**
* ---------- ADD BLOCK ----------
*/

/**
* @brief create a new block to the end of a block list.
* @param char* bid: id of the block to create. 
*        int nid: id of the node were the block list is rattached to.
* @return return the new node.
*/
t_block* new_block(t_block* head_block, char* bid, int nid)
{
    t_block* current = head_block;
    t_block* new_block = secure_malloc(sizeof(t_block));

    if (new_block == NULL)
    {
        print_error_message(ERR_NO_MORE_RESSOURCES);
        free(new_block);
        return head_block;
    }

    new_block->bid = bid;
    new_block->next = NULL;

    if (head_block == NULL)  // if no block has been initialised yet
    {
        return new_block;
    }

    if (same_bid(current, new_block) == 1)
    {   
        if (nid != -1)
        {
            print_error_message(ERR_BLOCK_ALREADY_EXIST);
        }
        free(new_block);
        return head_block;
    }

    while (current->next != NULL)
    {
        if (same_bid(current, new_block) == 1)
        {
            if (nid != -1)
            {
                print_error_message(ERR_BLOCK_ALREADY_EXIST);
            }
            free(new_block);
            return head_block;
        }
        current = current->next;
    }
    current->next = new_block;
    new_block->next = NULL;
    return head_block;
}

/**
* @brief add a new block to a given node.  
* @param t_list* head: head of the linked list.
*        string_array* array: contain the node id and the block id in different element of an array of string.
* @return return the modified head with the new block.
*/
t_list* add_block(t_list* head, string_array* array)
{
    t_list* current = head;
    
    char* bid = secure_malloc(sizeof(char) * my_strlen(array->array[2]));
    my_strcpy(array->array[2], bid);
    int nid = positive_atoi(array->array[3]);

 
    if (nid == -1)  // if the nid is *
    {
        while (current != NULL)
        {
            current->head_block = new_block(current->head_block, bid, nid);
            current = current->next;
        }
        return head;
    }

    while (current != NULL && current->nid != nid)  // seach for the node
    {
        current = current->next;
    }

    if (current == NULL)  // check if the node exist
    {
        print_error_message(ERR_NODE_NOT_FOUND); 
        return head;
    }

    current->head_block = new_block(current->head_block, bid, nid);

    if (current->head_block == NULL)  // check if new_block was succefull
    {
        return 0;
    }

    print_error_message(OK);
    return head;
}

#ifdef UNIT_TEST_ADD_BLOCK
int main()
{
    t_list* head = secure_malloc(sizeof(t_list*));
    head->nid = 1;
    head->next = NULL;
    
    string_array* test = secure_malloc(sizeof(string_array));
    test->array = secure_malloc(sizeof(char*) * 4);
    test->array[0] = "add";
    test->array[1] = "block";
    test->array[2] = "1";
    test->array[3] = "1";
    test->size = 4;

    add_block(head, test);

    if (my_strcmp(head->head_block->bid, "1") == 0)
    {
        free_linked_list(head);
        free_array(test);
        printf("True\n");
        return 1;
    }
    free_linked_list(head);
    free_array(test);
    printf("False\n");
    return 0;
}
#endif

/**
* ---------- ADD NODE ----------
*/

/**
* @brief create a node at the end of a linked list.
* @param int id: id of the created node.
* @return return the new node created.
*/
t_list* create_node(int id)
{
    t_list* new_node = secure_malloc(sizeof(t_list));
    
    if (new_node == NULL)
    {
        print_error_message(ERR_NO_MORE_RESSOURCES);
        free(new_node);
        return 0;
    }

    new_node->nid = id;
    new_node->next = NULL;

    return new_node;
}

/**
* @brief add a node in a linked list.
* @param t_list* head: head of the linked list.
*        string_array* array: array with the info of the node id.
* @return return the head of the linked list.
*/
t_list* add_node(t_list* head, string_array* array)
{
    t_list* current = head;
    int id = positive_atoi(array->array[2]);
    if (current == NULL)
    {
        current = create_node(id);
        print_error_message(OK);
        return current;
    }

    while (current->next != NULL) 
    {
        current = current->next;
    }
    
    if (same_nid(head, id) == 0) 
    {
        current->next = create_node(id);
        print_error_message(OK);
    }
    else 
    {
        print_error_message(ERR_NODE_ALREADY_EXIST);
    }

    return head;
}

#ifdef UNIT_TEST_ADD_NODE
int main()
{
    t_list* head = secure_malloc(sizeof(t_list*));
    head->nid = 1;
    head->next = NULL;

    string_array* test = secure_malloc(sizeof(string_array*));
    test->array = secure_malloc(sizeof(char*) * 3);
    test->array[0] = "add";
    test->array[1] = "node";
    test->array[2] = "2";
    test->size = 3;

    add_node(head, test);

    if (head->next->nid == 2)
    {
        free_linked_list(head);
        free_array(test);
        printf("True\n");
        return 1;
    }
    free_linked_list(head);
    free_array(test);
    printf("False\n");
    return 0;
}
#endif

/**
* ---------- REMOVE BLOCK ----------
*/

/**
* @brief removes a block inside a linked list.
* @param t_block*: head: head of the linked list.
*        char* bid: id of the block to remove.
*        int nid: id of the node were the block list is.
* @return return the head once the block has been removed.
*/
t_block* remove_block(t_block* head, char* bid, int nid)
{
    t_block* current = head;
    t_block* temp = NULL;

    if (head == NULL)  // check if the linked list isn't NULL
    {
        print_error_message(ERR_BLOCK_NOT_FOUND);
        return head;
    }

    if (current->next == NULL)  // exception if the linked list only has one element
    {
        if (strcmp(current->bid, bid) != 0)  // if it's not the block that need to be removed
        {   
            if (nid != 0)
            {
                print_error_message(ERR_BLOCK_NOT_FOUND);
            }
            return head;            
        }
    
        free(head->next);
        head = NULL;
        return head;  // exactly like removing the only block
    }

    while (current->next != NULL && my_strcmp(current->next->bid, bid) != 0)  // search for the block to remove
    {
        current = current->next;
    }

    if (current->next == NULL)  // check if the block has been found
    {
        if (nid != -1)
        {
            print_error_message(ERR_BLOCK_NOT_FOUND);
        }
    
        return head;
    }

    temp = current->next;
    current->next = temp->next;
    free(temp);
    
    return head;
}

#ifdef UNIT_TEST_REMOVE_BLOCK
int main()
{
    t_list* head = secure_malloc(sizeof(t_list*));
    head->nid = 1;
    head->head_block = secure_malloc(sizeof(t_block*));
    head->head_block->bid = "1";
    head->head_block->next = NULL;
    head->next = secure_malloc(sizeof(t_list*));
    head->next->nid = 2;
    head->next->next = NULL;

    head->head_block = remove_block(head->head_block, "1", 1);

    if (head->head_block->bid == NULL)
    {
        printf("True\n");
        return 1;
    }
    printf("False\n");
    return 0;
}
#endif

/**
* ---------- RM BLOCK ----------
*/

/**
* @brief removes a given block from the linked list.
* @param t_list* head: head of the linked list.
*        string_array* array: struct with a char**, containing the node id and the block id.
* @return return the modified head.
*/
t_list* rm_block(t_list* head, string_array* array)
{
    t_list* current = head;
    char* bid = array->array[2];
    int nid = positive_atoi(array->array[3]);

    if (nid == -1)  // if the nid is *
    {
        while (current != NULL)
        {
            current->head_block = remove_block(current->head_block, bid, nid);
            current = current->next;
        }

        print_error_message(OK);
        return head;
    }

    while (current != NULL && current->nid != nid)  // search for the node
    {
        current = current->next;
    }

    if (current == NULL)  // check if the node exist
    {
        print_error_message(ERR_NODE_NOT_FOUND); 
        return head;
    }
    
    current->head_block = remove_block(current->head_block, bid, nid);

    print_error_message(OK);

    return head;
}

#ifdef UNIT_TEST_RM_BLOCK
int main()
{
    t_list* head = secure_malloc(sizeof(t_list*));
    head->nid = 1;
    head->head_block = secure_malloc(sizeof(t_block*));
    head->head_block->bid = "1";
    head->head_block->next = NULL;
    head->next = secure_malloc(sizeof(t_list*));
    head->next->nid = 2;
    head->next->next = NULL;

    string_array* test = secure_malloc(sizeof(string_array));
    test->array = secure_malloc(sizeof(char*) * 4);
    test->array[0] = "rm";
    test->array[1] = "block";
    test->array[2] = "1";
    test->array[3] = "1";
    test->size = 4;

    head = rm_block(head, test);

    if (head->head_block->bid == NULL)
    {
        printf("True\n");
        return 1;
    }
    printf("False\n");
    return 0;
}
#endif

/**
* ---------- RM NODE ----------
*/

/**
* @brief count number of node in the list.
* @param t_list* head: head of the linked list.
*        string_array* array: structure with a char**, containing the node id.
* @return return the number of node.
*/
t_list* rm_node(t_list* head, string_array* array)
{
    t_list* current = head;
    t_list* temp = NULL;

    int nid = positive_atoi(array->array[2]);
    if (nid == -1)
    {
        head = NULL;
        print_error_message(OK);
        return head;
    }

    if (current == NULL)  // if the head is NULL
    {
        print_error_message(ERR_NODE_NOT_FOUND);
        return head;
    }

    if (current->nid == nid)
    {
        head = head->next;
        print_error_message(OK);
        return head; 
    }

    while (current->next != NULL && current->next->nid != nid)  // searches for the node
    {
        current = current->next;
    }

    if (current->next == NULL)
    {
        print_error_message(ERR_NODE_NOT_FOUND);
        return head;
    }

    temp = current->next;
    current->next = temp->next;

    print_error_message(OK);
    
    free(temp);
    return head;
}

#ifdef UNIT_TEST_RM_NODE
int main()
{
    t_list* head = secure_malloc(sizeof(t_list*));
    head->nid = 1;
    head->head_block = secure_malloc(sizeof(t_block*));
    head->head_block->bid = "1";
    head->head_block->next = NULL;
    head->next = secure_malloc(sizeof(t_list*));
    head->next->nid = 2;
    head->next->next = NULL;

    string_array* test = secure_malloc(sizeof(string_array));
    test->array = secure_malloc(sizeof(char*) * 4);
    test->array[0] = "rm";
    test->array[1] = "node";
    test->array[2] = "2";
    test->size = 3;

    head = rm_node(head, test);

    if (head->next == NULL)
    {
        printf("True\n");
        return 1;
    }
    printf("False\n");
    return 0;
}
#endif

/**
* ---------- MY SYNC ----------
*/

/**
* @brief to add all block in all node.
* @param t_list* head: it's just my linked list.
*        string_array* array: structure used in other functions.
* @return return my linked list.
*/
t_list* my_sync(t_list* head, char* empty){
    
    if (head == NULL)
    {
        print_error_message(OK);
        return head;
    }

    (void)empty;
    t_list* current = head;
    t_list* temp = head;
    t_block* temp_block = head->head_block;
    t_block* current_block = temp_block;

    while (temp != NULL) {

        if (is_synced(head) == 1) 
        {
            print_error_message(OK);
            return head;
        }

        if (temp_block == NULL)
        {
            current = head;
            temp = temp->next;
            temp_block = temp->head_block;
            current_block = current->head_block;
        }

        if (current == NULL)
        {
            if (temp_block != NULL) {
            
                temp_block = temp_block->next;

                if (temp_block != NULL) {
                    current = head;
                    current_block = current->head_block;
                }
         
                if (temp->next == NULL && temp_block == NULL) {
                    print_error_message(OK);
                    return head;
                }

            }
        }
        else 
        {
            if (temp_block != NULL) 
            {
                if (same_bid(current_block, temp_block) != 1) 
                {    
                    if (current_block != NULL) {
                        while (current_block->next != NULL) {
                            current_block = current_block->next;
                        }
                    }
                    add_block_duplicate(head, temp_block->bid, current->nid);
                }               
            }
            
            current = current->next;

            if (current != NULL) {
                current_block = current->head_block;
            }
        }
    }
    print_error_message(OK);
    return head;
}

#ifdef UNIT_TEST_MY_SYNC
int main()
{
    t_list* head = secure_malloc(sizeof(t_list*));
    head->nid = 1;
    head->head_block = secure_malloc(sizeof(t_block*));
    head->head_block->bid = "3";
    head->head_block->next = NULL;
    head->next = secure_malloc(sizeof(t_list*));
    head->next->nid = 2;
    head->next->head_block = secure_malloc(sizeof(t_block*));
    head->next->head_block->bid = "1";
    head->next->next = NULL;

    head = my_sync(head, "");

    if (strcmp(head->head_block->bid->next, "1") == 0)
    {
        printf("True\n");
        return 1;
    }
    printf("False\n");
    return 0;
}
#endif

/**
 * ---------- QUIT ----------
 */

/**
* @brief save the current linked list in a file and quit the program.
* @param t_list* head: head of the linked list to save.
*        char* string: string to know if the command quit was called or if the EOF was reached.
* @return return a modified head to tell the program to quit.
*/
t_list* quit(t_list* head, char* string)
{
    t_list* quit = secure_malloc(sizeof(t_list));
    quit->nid = -1;

    if (strcmp(string, "\0") == 0){
        return quit;
    }

    char* filename = "savefile.txt";
    remove(filename);
    int fd = secure_open(filename, O_WRONLY | O_CREAT);
    
    if (fd == -1)
    {
        return 0;
    }

    chmod(filename, 0777);

    if (write_linked_list(head, fd) == 0)
    {
        close(fd);
        return 0;
    }

    close(fd);
    free_linked_list(head);
    printf("Backing up blockchain...\n");

    return quit;
}

#ifdef UNIT_TEST_QUIT
int main()
{
    t_list* head = secure_malloc(sizeof(t_list*));
    head->nid = 1;
    head->head_block = secure_malloc(sizeof(t_block*));
    head->head_block->bid = "1";
    head->head_block->next = NULL;
    head->next = secure_malloc(sizeof(t_list*));
    head->next->nid = 2;
    head->next->next = NULL;

    head = quit(head, "");

    printf("True\n");
    return 1;
}
#endif

/**
 * ---------- SELECT ADD ----------
 */

/**
 * @brief takes a string which is a part of the user input, to know the function to call.
 * @param t_list* head: head of the linked list that will be modified.
 *        char* input: string containing the user's input.
 * @return return the head of the list once modified.
 */
t_list* select_add(t_list* head, char* input)
{
    string_array* array = my_split(input, " ");

    t_param comutator[] =
    {
        {"node", add_node, 0},
        {"block", add_block, 0},
        {0,0,0}
    };

    t_param* tmp = comutator;

    while (tmp->str != 0) 
    {
        if (my_strcmp(tmp->str, array->array[1]) == 0) 
        {
            head = tmp->func(head, array);
            free_array(array);
            return head;
        }
        
        tmp += 1;
    }
    
    free_array(array);
    print_error_message(ERR_COMMAND_NOT_FOUND);

    return head;
}

#ifdef UNIT_TEST_SELECT_ADD
int main()
{
    t_list* head = secure_malloc(sizeof(t_list*));
    head->nid = 1;
    head->head_block = secure_malloc(sizeof(t_block*));
    head->head_block->bid = "1";
    head->head_block->next = NULL;
    head->next = secure_malloc(sizeof(t_list*));
    head->next->nid = 2;
    head->next->next = NULL;

    char* input = "add node 3";

    head = select_add(head, input);

    if (head->next->next->nid == 3)
    {
        printf("True\n");
        return 1;
    }
    printf("False\n");
    return 0;
}
#endif

/**
 * ---------- SELECT RM ----------
 */

/**
 * @brief takes a string which is a part of the user input, to know the function to call.
 * @param t_list* head: head of the linked list that will be modified.
 *        char* input: string containing the user's input.
 * @return return the head of the list once modified.
 */
t_list* select_rm(t_list* head, char* input)
{
    string_array* array = my_split(input, " ");

    t_param comutator[] =
    {
        {"node", rm_node, 0},
        {"block", rm_block, 0},
        {0,0,0}
    };

    t_param* tmp = comutator;

    while (tmp->str != 0) 
    {
        if (my_strcmp(tmp->str, array->array[1]) == 0) 
        {
            head = tmp->func(head, array);
            free_array(array);
            return head;
        }
        
        tmp += 1;
    }
    
    free_array(array);
    print_error_message(ERR_COMMAND_NOT_FOUND);

    return head;
}

/**
 * ---------- SELECT LS ----------
 */

/**
 * @brief takes a string which is a part of the user input, to know the function to call.
 * @param t_list* head: head of the linked list that will be modified.
 *        char* input: string containing the user's input.
 * @return return the head of the list once modified.
 */
t_list* select_ls(t_list* head, char* input)
{
    string_array* array = NULL;
    
    if (my_strcmp("ls\n", input) == 0) {
        array = my_split("empty ls", " ");
    }else {
        array = my_split(input, " ");
    }

    t_param comutator[] =
    {
        {"-l", print_linked_list, 0},
        {"ls", print_ls, 0},
        {0,0,0}
    };

      t_param* tmp = comutator;

    while (tmp->str != 0) 
    {
        if (my_strcmp(tmp->str, array->array[1]) == 0) 
        {
            head = tmp->func(head, array);
            free_array(array);
            return head;
        }
        
        tmp += 1;
    }
    
    free_array(array);
    print_error_message(ERR_COMMAND_NOT_FOUND);

    return head;
}

#ifdef UNIT_TEST_SELECT_LS
int main()
{
    t_list* head = secure_malloc(sizeof(t_list*));
    head->nid = 1;
    head->head_block = secure_malloc(sizeof(t_block*));
    head->head_block->bid = "1";
    head->head_block->next = NULL;
    head->next = secure_malloc(sizeof(t_list*));
    head->next->nid = 2;
    head->next->next = NULL;

    char* input = "ls -l";

    head = select_ls(head, input);
    
    printf("True\n");
    return 1;
}
#endif

/**
 * ---------- COMPARE INPUT ----------
 */

/**
 * @brief takes a string containing the input of the user, concatain every word into a char** and call the corresponding function.
 * @param char* input: string that is concatained and read from.
 *        t_list* head: head of the linked list to manipulate.
 * @return return the head once modified.
 */
void* compare_input(char* input, t_list* head)
{
    string_array* array = my_split(input, " ");
    
    t_param comutator[] =
    {
        {"add", 0, select_add},
        {"rm", 0, select_rm},
        {"sync", 0, my_sync},
        {"ls", 0, select_ls},
        {"quit", 0, quit},
        {"\0", 0, quit},
        {0,0,0}
    };

    t_param* tmp = comutator;

    while (tmp->str != 0) 
    {
        if (my_strcmp(tmp->str, array->array[0]) == 0) 
        {
            head = tmp->test(head, input);
            free_array(array);
            return head;
        }
        
        tmp += 1;
    }

    print_error_message(ERR_COMMAND_NOT_FOUND);  
    free_array(array);
    return head;
}

#ifdef UNIT_TEST_COMPARE_INPUT
int main()
{
    t_list* head = secure_malloc(sizeof(t_list*));
    head->nid = 1;
    head->head_block = secure_malloc(sizeof(t_block*));
    head->head_block->bid = "1";
    head->head_block->next = NULL;
    head->next = secure_malloc(sizeof(t_list*));
    head->next->nid = 2;
    head->next->next = NULL;

    char* input = "add node 3";

    head = compare_input(input, head);

    if (head->next->next->nid == 3)
    {
        printf("True\n");
        return 1;
    }
    printf("False\n");
    return 0;
}
#endif

#ifdef UNIT_TEST_SELECT_RM
int main()
{
    t_list* head = secure_malloc(sizeof(t_list*));
    head->nid = 1;
    head->head_block = secure_malloc(sizeof(t_block*));
    head->head_block->bid = "1";
    head->head_block->next = NULL;
    head->next = secure_malloc(sizeof(t_list*));
    head->next->nid = 2;
    head->next->next = NULL;

    char* input = "rm node 2";

    head = select_rm(head, input);

    if (head->next == NULL)
    {
        printf("True\n");
        return 1;
    }
    printf("False\n");
    return 0;
}
#endif

/**
 * ---------- MY BLOCKCHAIN ----------
 */

/**
* @brief recover the linked list when the program starts, print info about the linked list and read the input of the user.
* @param t_list* head: head of the linked list.
* @return return the linked list once the program is done.
*/
t_list* my_blockchain(t_list* head)
{
    char* nbr = NULL;
    int loop = 1;
    t_list* tmp = NULL;
    char* buff = NULL;

    head = recover_savefile("savefile.txt");
    if (head == NULL)
    {
        printf("No Backup Found: Starting New Blockchain\n");
    }
    else
    {
        printf("Restoring From Backup\n");
    }

    while (loop)
    {
        nbr = my_itoa(nbr_node(head));
        if (is_synced(head) == 1) 
        {
            write(1, "[s", 2);
            write(1, nbr, my_strlen(nbr));
            write(1, "]>", 2);
        }
        else
        {
            write(1, "[-", 2);
            write(1, nbr, my_strlen(nbr));
            write(1, "]>", 2);
        }

        buff = secure_malloc(sizeof(char) * 100);

        if (secure_read(0, buff, 100) == -1)
        {
            return NULL;
        }
        
        tmp = compare_input(buff, head);

        if (tmp != NULL)
        {
            if (tmp->nid == -1)
            {
                loop = 0;
            }
        } 
        
        head = tmp;
        free(buff);
    }
    return head;
}

#ifdef UNIT_TEST_MY_BLOCKCHAIN
int main()
{
    t_list* head = NULL;
    head = my_blockchain(head)
    if (head != NULL)
    {
        printf("True\n");
        return 1;
    }
    printf("False");
    return 0;
}
#endif