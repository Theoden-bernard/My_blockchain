# Remove Block

## 📝 Description :
#### Remove a block attached to a node. If the id of the node is 
---
## Parameters :
- head: head of the block list were the node needs to be removed.
- bid: id of the block to remove.
- nid: id attached to the block list.
---
## Return :
- Return the head once the block has been removed.
---
## Proto :
```c
t_block* remove_block(t_block* head, char* bid, int nid);
```
---
## Exemple : 
```c
remove_block(head, "5", 1);
```

```$> head```
