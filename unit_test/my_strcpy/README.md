# My Strcpy

## 📝 Description :
#### Copy the content of a string into another string. The two string need to be malloc before.
## Parameters :
- string : string that is copied.
- result : string were the result is copied.
---
## Return :
- Doesn't return anything.
---
## Exemple : 
```c
char* string = malloc(sizeof(char) * 20);
char* result = malloc(sizeof(char) * 20);
string = "abcdefghijklmnopqrstu";

my_strcpy(string, result);
printf("%s\n", result);
```
value of result : abcdefghijklmnopqrstu;