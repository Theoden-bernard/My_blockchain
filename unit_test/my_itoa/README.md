# My Itoa

## 📝 Description :
#### My Itoa is a function who converted a integer in to array. it can take positive and negative numbers.
---
## Parameters :
- nbr: The number that must be converted to an array.
---
## Return :
- Return a **nbr_in_to_char** variable who is an array.
- Return **"0"** if ```nbr == 0``` at the beginning of the programme.
---
## Proto
```c 
char *my_itoa(int num)
```
*num* the signed int to convert
*converted string (this sting has been allocated in itoa and must be freed later on

## Exemple : 
```c
my_itoa(34);
my_itoa(-34);
```
my_atoi(34) = "34"
my_atoi(-34) = "-34"