# Secure Open

## 📝 Description :
#### <u>**secure_open**</u>: It's a function who check if open has worked
---
## Parameters :
- pathname : Name of the file that you try open.
- flag : These allow open to function differently.

## Return :
1. return <span style="color:lightblue"> **result**</span>: Its file descriptor.
2. return <span style="color:lightblue">**-1**</span>: If open fails.

## Proto :
```c
int secure_open(char* pathname, int flag)
```

## Exemple : 

### <u>*exemple n°1*</u> :
```c
// in this exemple buff has a size of 10
secure_open(pathname, O_APPEND);
```
<u>Return value</u> :
```c
$> 1245... //fd (your file desciptor)
```
---

### <u>*exemple n°2*</u> :
```c
// in this exemple buff has a size of 5
secure_open(pathname, O_APPEND);
```
<u>Return value</u> :
```c
$> -1 // probably because your pathname is not define or the file name doesn't exist.
```
