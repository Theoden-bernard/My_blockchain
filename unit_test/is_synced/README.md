# Is Synced

## 📝 Description :
#### <u>**is_synced**</u>: It's a function who check if your blockchain is synced or not. It's return 1 if my linked list is sync and 0 if it not sync
---
## Parameters :
- head : A pointer on the head of the linked list

## Return :
1. return <span style="color:lightblue"> **1** </span> : if your linked list is <span style="color:lightblue"> **sync** </span>.
2. return <span style="color:lightblue"> **0** </span> : if your linked list is <span style="color:lightblue"> **not sync** </span>.

## Proto :
```c
int is_synced(t_list* head)
```

## Exemple : 

### <u>*exemple n°1*</u> :

    Plan: head =  [3]->[4]->[1]-> NULL
                   |    |    |
                   ˇ    ˇ    ˇ
                  [2]  [4] [NULL]
                   |    |
                   ˇ    ˇ
                  [1] [NULL]
                   |
                   ˇ
                 [NULL]


```c 
is_synced(head) 
```
---
<u>**Return value</u>** : <br>
```$> 0```

---

### <u>*exemple n°2*</u> :

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


```c 
is_synced(head) 
```
---
<u>**Return value</u>** : <br>
```$> 1```

---