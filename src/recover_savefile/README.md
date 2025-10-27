# Recover Savefile

## 📝 Description :
#### Open a file and reads line by line its content, until the end is reached. Once a line is read, it is given to another function (recover_linked_list) to recreate a linked list.
---
## Parameters :
- filename: path of the file to open.
---
## Return :
- Return the linked list once recreated.
---
## Proto :
```c
t_list* recover_savefile(char* filename)
```
---
## Exemple : 
```c
recover_savefile("Savefile.txt");
```

```$> head``` 
