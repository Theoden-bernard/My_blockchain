# Init Sync

## 📝 Description :
#### <u>**init_sync**</u>: It's a function who initialise my sturuct s_sync. The function allocates all the necessary variables in the structure, so remember to free your structure with the dedicated function.
---
## Parameters :
- head: A pointeur on my head of my linked list
- my_sync_struct: Pointer on my sync struc 
---
## Return :
- my_sync_struct: Return a pointer on my_sync_struct
---
## Proto :
```c
t_sync* init_sync_struct(t_list* head, t_sync* my_sync_struct)
```
---
## Exemple : 

returns a pointer to an allocated t_sync structure 
