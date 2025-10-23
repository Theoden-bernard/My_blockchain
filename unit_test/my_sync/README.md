# My sync

## 📝 Description :
#### **<u>my_sync</u>**: Is a function that synchronises your blocks across all your nodes.
---
## Parameters :
- head : A pointer on the head of the linked list
- empy : Is a parameter that will be useless to us, but since we are using function pointers, our functions must contain a t_list* and a char*.

## Return :
1. return head : my_sync return a pointer on the head of the linked list synced.

## Proto :
```c
t_list* my_sync(t_list* head, char* empty)
```

## Exemple : 

### <u>*befor sync*</u> :
    Plan: head =  [3]->[4]->[1]-> NULL
                   |    |    |
                   ˇ    ˇ    ˇ
                  [2]  [4]  [NULL]
                   |    |  
                   ˇ    ˇ
               [NULL] [NULL]

```c
my_sync(head, input)
```
### <u>*after sync*</u> :

    Plan: head =  [3]->[4]->[1]-> NULL
                   |    |    |
                   ˇ    ˇ    ˇ
                  [2]  [4]  [4]
                   |    |    |
                   ˇ    ˇ    ˇ
                  [4]  [2]  [2]
                   |    |    |
                   ˇ    ˇ    ˇ
               [NULL] [NULL] [NULL]