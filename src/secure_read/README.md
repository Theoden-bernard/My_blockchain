# Secure Read

## 📝 Description :
#### <u>**secure_read**</u>: It's a function who check is read as work
---
## Parameters :
- fd : It's the decryption file that allows access to the files.
- buff : It's the string that read function as read.
- size : this is the size of what read should read.

## Return :
1. return <span style="color:lightblue"> **result**</span>: It's the number of bits read.
2. return <span style="color:lightblue">**-1**</span>: If read fail.

## Proto :
```c
int secure_read(int fd, void* buff, size_t size)
```

## Exemple : 

### <u>*exemple n°1*</u> :
```c
// in this exemple buff as a size of 10
secure_read(fd, buff, 10);
```
<u>Return value</u> :
```c
$> 10
```
---

### <u>*exemple n°2*</u> :
```c
// in this exemple buff as a size of 5
secure_read(fd, buff, 10);
```
<u>Return value</u> :
```c
$> -1
```