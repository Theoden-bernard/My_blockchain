# Secure malloc

## 📝 Description :
#### <u>**secure_malloc**</u>: It's a function who check if malloc has worked. Secure_malloc allocate a buffer in this function. <span style="color:red"> <u>**Warning**</u>:</span> **Don't forget to free when you no longer need your value.**
---
## Parameters :
- size : This is the size you need to allocate.

## Return :
1. return <span style="color:lightblue"> **buff**</span>: It's the number of bits writen.
2. return <span style="color:lightblue">**NULL**</span>: If malloc failed.

## Proto :
```c
void* secure_malloc(size_t size)
```

## Exemple : 

### <u>*exemple n°1*</u> :
```c
secure_malloc(size_t size)
```
<u>Return value</u> :
```c
$> buff
```
---

### <u>*exemple n°2*</u> :
```c
secure_malloc(size_t size)
```
<u>Return value</u> :
```c
$> NULL
```