# Compare input

## 📝 Description :
<u>**Compare input**</u>: Is a function that uses a function pointer system. It takes the user's input and a pointer to the head of the linked list. The input will be processed to determine which function we need based on what was sent, and head will be sent to process our linked list afterwards.

---
## Parameters :
- <u>**input**</u> : It is the string who as send for user.
- <u>**head**</u> : It is a pointer on the head of the linked list

## Return :
1. <u>**head**</u>: If it finds a similarity between my pointer table on function and my input

2. <u>**head**</u>: If it not finds a similarity between my pointer table on function and my input

## Proto :
```c
void* compare_input(char* input, t_list* head)
```

## Exemple : 

```c
// Is a structur to my pointer on function
typedef struct s_param {
    char* str; // The input will compar
    t_list*(*func)(t_list*, string_array*); // A type of pointeur on function
    t_list*(*test)(t_list*, char*); // A other type of pointeur on function
}t_param;

// I creat a array of my structure whith the info inportant for my exercise
t_param comutator[] =
{
    {"add", 0, select_add}, //if input == add i will execut select_add function
    {"rm", 0, select_rm}, //if input == rm i will execut select_rm function
    {"sync", 0, my_sync}, //if input == sync i will execut my_sync function
    {"ls", 0, select_ls}, //if input == ls i will execut select_ls function
    {"quit", 0, quit}, //if input == quit i will execut quit function
    {"\0", 0, quit}, //if input == \0(/d) i will execut quit function
    {0,0,0} // End of my array 
};
```
<br>
After this initialisation my var i will brows my array until my input == str(on my structur) or the end of my array.

And i will return a pointeur on the head of my linked list

<u>For exemple</u>: <br>
**head** == [2]->[6]-> NULL

```$> head```
