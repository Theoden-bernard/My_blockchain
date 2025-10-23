# My Readline

## 📝 Description :
#### read the content of a file until a newline character or the EOF is reached.
---
## Parameters :
- fd: value of the file descriptor of the file to read.
---
## Return :
- return the characters stocked inside a string.
---
## Proto :
```c
char* my_readline(int fd);
```
---
## Exemple : 
```c
int fd = secure_open("toto.txt");
char* buff = my_readline(fd);
```

```$> buff```
