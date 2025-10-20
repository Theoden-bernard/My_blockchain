# Add Node

## 📝 Description :
#### Add Node is a function who add a node in the link list.
---
## Parameters :
- head: head of the link list.
- array: structur with all the info on the futur node.
---
## Return :
- Return a **current** if head is NULL
- Return **head** if everything went well.
---
## Exemple : 

Befor add node:
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