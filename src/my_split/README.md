# My Split

## 📝 Description :
#### Split a char* into multiple one. They are split when the separator is found.  
---
## Parameters :
- string: string to split.
- separator: separator that define were to split the string.
---
## Return :
- return a structure with an array of string and the size of the array as components.
---
## Proto :
```c
string_array* my_split(char* string, char* separator);
```
---
## Exemple : 
```c
my_split("testing this function", " ");
```

```$> string_array = ["testing", "this", "function"]```