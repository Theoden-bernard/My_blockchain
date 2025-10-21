# Secure Open

## 📝 Description :
#### Secure open use the function open and verifies the result of it. Depending on the result, it returns -1 if it failed and the value of the file descriptor if it succeded.
---
## Parameters :
 - pathname: path of the file to open. The path can change depending on were you are in the files.
 - flags: option to use use when calling open, to know what permissions the user can have and if other modifications are necessary.
---
## Return :
- Return the value of the file descriptor.
- Return -1 if the the read failed.
---
## Exemple : 
```c
secure_open("file.txt", O_RDWR | O_CREATE);
```
Value returned by secure_read: value of the file descriptor.