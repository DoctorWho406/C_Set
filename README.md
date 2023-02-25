# C_Set
Simple implementation of Set in C

# Usage
You could create a dll using `make.bat` (it require clang.exe).<br>
This will generate a ready-to-use directory called `set` containing the necessary libraries and includes.

## Command with clang.exe
```
clang -shared -o set\lib\set.dll -I include -I library\linkedlist\include -L library\linkedlist\lib -l linkedlist src\*.c
```
N.B.<br>
It requires that the `set/lib` folder exists

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
            <td rowspan=2>set_table_create</td>
            <td>set_table_t**</td>
            <td>Pointer to set</td>
            <td rowspan=2>int</td>
            <td rowspan=2>0 on succes, neagtive number on failure</td>
            <td rowspan=2>Create the set_table stucture with desired hasmap size</td>
        </tr>
        <tr>
            <td>size_t</td>
            <td>The desired size of the hashmap</td>
        </tr>
        <tr>
            <td rowspan=3>set_table_insert</td>
            <td>set_table_t*</td>
            <td>Pointer to the set_table</td>
            <td rowspan=3>int</td>
            <td rowspan=3>0 on succes, neagtive number on failure</td>
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
        <tr>
            <td>set_table_destroy</td>
            <td>set_node_t*</td>
            <td>Pointer to the set_table</td>
            <td colspan=2>void</td>
            <td>Destory the set and clear all used memory</td>
        </tr>
    </tbody>
</table>

# Example

Create executable using `example.bat` (it require clang.exe)

## Command with clang.exe
```
clang -o examples\bin\example.exe -I include -I examples\include -I library\linkedlist\include -L set\lib -lset examples\src\*.c 
```
N.B.<br>
It requires that the `examples/bin` folder exists.<br/>
Copy `linkedlist.dll` from `linkedlist\lib` folder and `set.dll` from `set\lib` to `examples/bin` folder

## Run it
```
./examples/bin/example.exe
```