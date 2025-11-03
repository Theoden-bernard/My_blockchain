# Write Linked List

## 📝 Description :
#### Write a linked list into a file.
---
## Parameters :
- head: head of the linked list.
- fd: file descriptor of the file to write in.
---
## Return :
- Return 1 if the programm succeded, 0 if not.
---
## Proto :
```c
int write_linked_list(t_list* head, int fd);
```
---
## Exemple : 
```c
fd = open("savefile.txt");
head = [2]->[3]->[4]->NULL
        |    |    |
        v    v    v
      ["1"]["2"]["1"]
        |    |    |
        v    v    v
       NULL NULL NULL      

int write_linked_list(head, fd);
```

```$> 1```