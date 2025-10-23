# Secure Write

## 📝 Description :
#### <u>**secure_write**</u>: It's a function who check is write as work
---
## Parameters :
- fd : It's the decryption file that allows access to the files.
- buff : It's the string that write function must write.
- size : this is the size of what write should write.

## Return :
1. return <span style="color:lightblue"> **result**</span>: It's the number of bits writing.
2. return <span style="color:lightblue">**-1**</span>: If write fail.

## Proto :
```c
int secure_write(int fd, void* buff, size_t size)
```

## Exemple : 

### <u>*exemple n°1*</u> :
```c
// in this exemple buff as a size of 10
secure_write(fd, buff, 10);
```
<u>Return value</u> :
```c
$> 10
```
---

### <u>*exemple n°2*</u> :
```c
// in this exemple buff as a size of 5
secure_write(fd, buff, 10);
```
<u>Return value</u> :
```c
$> -1
```