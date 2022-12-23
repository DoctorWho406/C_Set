# C_Set
Simple implementation of Set in C

# Usage
You could create a dll using `make.bat` (it require clang.exe)

## Command with clang.exe
```
clang -shared -o library\hash.dll src\Hash.c

clang -shared -o library\set.dll -I include src\Set.c -l hash -l linkedlist -L library
```
N.B.<br>
It requires that the `library` folder exists and contains `linkedlist` library

# API

First of all implement your structure with the data you want. This must contain set_node_t node;

### Example
```C
struct string_item {
    set_node_t node;
    const char *string;
};
```

## Functions

<table>
    <thead>
        <tr>
            <th>Function</th>
            <th colspan=2><center>Parametrs</center></th>
            <th colspan=2><center>Return</center></th>
            <th>Explanation</th>
        </tr>
    </thead>
    <tbody>
        <tr>
            <td>set_table_new</td>
            <td>size_t</td>
            <td>The desired size of the hashmap</td>
            <td>set_table_t*</td>
            <td>Pointer to the set_table created or NULL on failure</td>
            <td>Create the set_table stucture with desired hasmap size</td>
        </tr>
        <tr>
            <td rowspan=3>set_table_insert</td>
            <td>set_table_t*</td>
            <td>Pointer to the set_table</td>
            <td rowspan=3>set_node_t*</td>
            <td rowspan=3>Pointer to the inserted item or NULL on failure</td>
            <td rowspan=3>Adds an item to the set</td>
        </tr>
        <tr>
            <td>set_node_t*</td>
            <td>Pointer to the item to be insert</td>
        </tr>
        <tr>
            <td>size_t</td>
            <td>Size of the data to compare in the structure<br/>In the above example the length of the string</td>
        </tr>
        <tr>
            <td rowspan=3>set_table_search</td>
            <td>set_table_t*</td>
            <td>Pointer to the set_table</td>
            <td rowspan=3>set_node_t*</td>
            <td rowspan=3>Pointer to the funded item or NULL if not</td>
            <td rowspan=3>Returns item of the set with same value of passed one if any</td>
        </tr>
        <tr>
            <td>set_node_t*</td>
            <td>Pointer to the item to be search</td>
        </tr>
        <tr>
            <td>size_t</td>
            <td>Size of the data to compare in the structure<br/>In the above example the length of the string</td>
        </tr>
        <tr>
            <td rowspan=3>set_table_remove</td>
            <td>set_node_t*</td>
            <td>Pointer to the set_table</td>
            <td rowspan=3>set_node_t*</td>
            <td rowspan=3>Pointer to the removed item or NULL on failure</td>
            <td rowspan=3>Remove a set item with the same value as the one passed in and return it</td>
        </tr>
        <tr>
            <td>set_node_t*</td>
            <td>Pointer to the item to be remove</td>
        </tr>
        <tr>
            <td>size_t</td>
            <td>Size of the data to compare in the structure<br/>In the above example the length of the string</td>
        </tr>
    </tbody>
</table>

# Example

Create executable using `example.bat` (it require clang.exe)

## Command with clang.exe
```
clang -shared -o library\hash.dll src\Hash.c

clang -o examples\bin\Example.exe -I include -I examples\include examples\src\main.c examples\src\StringItem.c src\Set.c -l hash -l linkedlist -L library
```
N.B.<br>
It requires that the `examples/bin` folder exists.<br/>
Copy `hash.dll` and `linkedlist.dll` from `library` folder to `examples/bin` folder

## Run it
```
./examples/bin/Example.exe
```