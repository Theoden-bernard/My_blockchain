# Secure Malloc

### 📝 Description :
Secure malloc is a function that allows you to verify that there were no problems during memory allocation.
---
### Parameters :
 - Size: the size of what needs to be allocated
---
### Return :
- Return a pointer on buff.
- Return **NULL** if buff has been initialised incorrectly.
---
### Exemple : 
```c
secure_malloc(sizeof(char) * 4);
```
size of buff = 4;

