# Secure Read

## 📝 Description :
#### Secure read use the function read and verifies the result of it. Depending on the result, it returns -1 if it failed and the number of bytes read if it succeded.
---
## Parameters :
 - fd: file descriptor of the file to read in.
 - buff: string that contains the content that was read.
 - size: size of the buff.
---
## Return :
- Return the number of bytes read.
- Return -1 if the the read failed.
---
## Exemple : 
```c
int fd = open("README.md");
char* buff = malloc(sizeof(char) * 100);
secure_read(fd, buff, strlen(buff));
```
value returned by secure_read: size of README.md