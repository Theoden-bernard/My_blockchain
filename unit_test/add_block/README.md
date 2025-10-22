# Add Block

## 📝 Description :
#### Add a block at the end of a block list. The block is created by calling the function new_block. The block list is found with the node id given. If the node that is supposed to contain the block list isn't found, it prints an error. If it works, print OK.
---
## Parameters :
- head: head of the linked list to modify.
- array: structure with all the info on the futur node.
---
## Return :
- return the linked list once modified.
- if the node hasn't been found, return the head without modifying it.
---
## Proto :
```c
t_list* add_block(t_list* head, string_array* array)
```
---
## Exemple : 
```c
add_block(head, array);
```

$> ```head```
