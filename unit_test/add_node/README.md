# Add Node

## 📝 Description :
#### Add Node is a function who add a node in the linked list. It creates the new node by calling the function new_node.
---
## Parameters :
- head: head of the linked list.
- array: structure with all the info on the futur node.
---
## Return :
- Return a **current** if head is NULL
- Return **head** if everything went well.
---
## Proto :
```c
t_list* add_node(t_list* head, string_array* array)
```
---
## Exemple : 

Before add node:
```
head = [2]->[3]->NULL
array = typedef struct s_string_array
{
    int size;
    char** array;
} string_array;

int size = 3
char** array = ["add"],["node"],["6"]
```

```c
add_node(head, array);
```

After add node:
```head = [2]->[3]->[6]->NULL```