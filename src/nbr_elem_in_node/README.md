# Nbr Elem In Node

## 📝 Description :
#### Count the number of block in a block list.
---
## Parameters :
- head_block : head of the block list.
---
## Return :
- return 0 : if head == NULL.
- return index : An index who is just the number of blocks in the block list.
---
## Proto :
```c
int nbr_elem_in_node(t_block* head_block);
```
---
## Exemple : 

**plan** :
head_block = ["3"]->["1]"->["7"]->["8"]->NULL
```c
nbr_elem_in_node(head_block);
```

```$> 4```