# Secure Write

## 📝 Description :
#### <u>**secure_write**</u>: It's a function who checks if write has worked
---
## Parameters :
- fd : file descriptor that allows access to the file.
- buff : string that the write function must write.
- size : this is the size of what write should write.

## Return :
1. return <span style="color:lightblue"> **result**</span>: Number of bits writen.
2. return <span style="color:lightblue">**-1**</span>: If write fail.

## Proto :
```c
int secure_write(int fd, void* buff, size_t size)
```

## Exemple : 

### <u>*exemple n°1*</u> :
```c
// in this exemple buff has a size of 10
secure_write(fd, buff, 10);
```
<u>Return value</u> :
```c
$> 10
```
---

### <u>*exemple n°2*</u> :
```c
// in this exemple buff has a size of 5
secure_write(fd, buff, 10);
```
<u>Return value</u> :
```c
$> -1
```