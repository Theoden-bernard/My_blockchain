# Secure Malloc

## 📝 Description :
#### Secure malloc is a function that allows you to verify that there were no problems during memory allocation. It take a size and allows to the latter then initialises the variable to 0 using memeset.
---
## Parameters :
 - size: the size of what needs to be allocated
---
## Return :
- Return a pointer on buff.
- Return **NULL** if buff has been initialised incorrectly.
---
## Exemple : 
```c
secure_malloc(sizeof(char) * 4);
```
Size of buff = 4;