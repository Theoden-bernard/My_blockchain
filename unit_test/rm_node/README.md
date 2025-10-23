# Rm Node

## 📝 Description :
#### rm_node is a function who remove a node in the linked list.rm_node free the node for you. 

---
## Parameters :
- head: Pointer on the head of the linked list.
- array: Pointer on the struct s_string_array.

## Return :
1. Return <span style="color:lightblue"> **head**</span>: After remove one node

## Proto :
```c
t_list* rm_node(t_list* head, string_array* array)
```
## Exemple : 

Before rm node:
```
head = [2]->[3]->[6]->NULL
array = typedef struct s_string_array
{
    int size;
    char** array;
} string_array;

int size = 3
char** array = ["rm"],["node"],["6"]
```

```c
rm_node(head);
```

After rm node:
```head = [2]->[3]->NULL```