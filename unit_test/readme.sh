if [ -z "$1" ]; then
    echo "Usage: $0 nom_du_projet"
    exit 1
fi

cd "$1"

echo "# Add Node

## 📝 Description :
#### your description
---
## Parameters :
- param_1 : description
- param_2 : description
... etc
---
## Return :
- first return : desciption
- second return : desciption
---
## Proto :
```c
your_type name_function(type param_1, type param_2)
```
param_1 context
param_2 context

---
## Exemple : 
```c
name_function(param_1, param_2);
```

$> return of your function" > README.md