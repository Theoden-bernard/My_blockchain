# Secure Open

## 📝 Description :
#### <u>**secure_open**</u>: It's a function who check is open as work
---
## Parameters :
- pathname : Name of the file that you try open.
- flag : These allow open to function differently.

## Return :
1. return <span style="color:lightblue"> **result**</span>: It's file descriptor.
2. return <span style="color:lightblue">**-1**</span>: If open fail.

## Proto :
```c
int secure_open(char* pathname, int flag)
```

## Exemple : 

### <u>*exemple n°1*</u> :
```c
// in this exemple buff as a size of 10
secure_open(pathname, O_APPEND);
```
<u>Return value</u> :
```c
$> 1245... //fd (your file desciptor)
```
---

### <u>*exemple n°2*</u> :
```c
// in this exemple buff as a size of 5
secure_open(pathname, O_APPEND);
```
<u>Return value</u> :
```c
$> -1 //probably because ypur pathname are not define or the file name does'n exist.
```
