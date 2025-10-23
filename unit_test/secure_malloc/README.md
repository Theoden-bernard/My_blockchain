# Secure malloc

## 📝 Description :
#### <u>**secure_malloc**</u>: It's a function who check is malloc as work. secure_malloc allocate a buffer in this function. <span style="color:red"> <u>**Warning**</u>:</span> **Think free when you no longer need your value.**
---
## Parameters :
- size : This is the size you need to allocate.

## Return :
1. return <span style="color:lightblue"> **buff**</span>: It's the number of bits writing.
2. return <span style="color:lightblue">**NULL**</span>: If malloc fail.

## Proto :
```c
void* secure_malloc(size_t size)
```

## Exemple : 

### <u>*exemple n°1*</u> :
```c
// in this exemple buff as a size of 10
secure_malloc(size_t size)
```
<u>Return value</u> :
```c
$> 10
```
---

### <u>*exemple n°2*</u> :
```c
// in this exemple buff as a size of 5
secure_malloc(size_t size)
```
<u>Return value</u> :
```c
$> -1
```