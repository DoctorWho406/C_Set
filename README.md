# C_Set
Simple implementation of Set in C

## Using
First create `hash.dll`

### Example with clang.exe
```
clang.exe -shared -o Hash/hash.dll Hash/Hash.c
```

Then create `linkedlist.dll`

### Example with clang.exe
```
clang.exe -shared -o LinkedList/linkedlist.dll LinkedList/LinkedList.c
``` 

Finally create executable using `SetTable.c` and `Set.c`
### Example with clang.exe
```
clang.exe -o Set.exe Set.c SetTable.c -l hash -L Hash -I Hash -l linkedlist -L LinkedList -I LinkedList
```

### Run it
Remember to copy `hash.dll` and `linkedlist.dll` to a reachable path (system path or root folder).
```
./Set.exe
```