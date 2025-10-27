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
// Is a structure to my pointer on function
typedef struct s_param {
    char* str; // The input will compare
    t_list*(*func)(t_list*, string_array*); // A type of pointeur on function
    t_list*(*test)(t_list*, char*); // A other type of pointeur on function
}t_param;

// I create an array of my structure with the info important for my exercise
t_param comutator[] =
{
    {"add", 0, select_add}, // If input == add i will execute select_add function
    {"rm", 0, select_rm}, // If input == rm i will execute select_rm function
    {"sync", 0, my_sync}, // If input == sync i will execute my_sync function
    {"ls", 0, select_ls}, // If input == ls i will execute select_ls function
    {"quit", 0, quit}, // If input == quit i will execute quit function
    {"\0", 0, quit}, // If input == \0(/d) i will execute quit function
    {0,0,0} // End of my array 
};
```
<br>
After this initialisation my var i will brows my array until my input == str(on my structure) or the end of my array.

And i will return a pointeur on the head of my linked list

<u>For exemple</u>: <br>
**head** == [2]->[6]-> NULL

```$> head```
