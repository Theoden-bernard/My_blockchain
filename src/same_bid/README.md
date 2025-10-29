# Same Bid

## 📝 Description :
#### Go through 2 block list and checks if they have the same blok id in them.
---
## Parameters :
- current_block: The first block list.
- temp_block: The second block list.
---
## Return :
- Return 1 if the block lists are equals, and 0 if not.
---
## Proto :
```c
int same_bid(t_block* current_block, t_block* temp_block);
```
---
## Exemple : 
```
current_block = [2]->[3]->NULL
temp_block = [2]->[3]->NULL
```

```c
same_bid(current_block, temp_block);
```

```$> 1```