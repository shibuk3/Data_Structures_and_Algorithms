### __

- Global variables are variables which are defined outside the function. The scope of global variables
begins at the point where they are defined and lasts till the end of the file/program. They have external 
linkage, which means that in other source files, the same name refers to the same location in memory.

- Static global variables are private to the source file where they are defined and do not conflict with
 other variables in other source files which would have the same name.

- Both global, as well as static variables, have static initialization, which means that if you don't
assign them a value, they will get initialized to 0 (common variables) or NULL (pointers).

- Static global variables: Variables declared as static at the top level of a source file 
(outside any function definitions) are only visible throughout that file.

- Static local variables: Variables declared as static inside a function are statically allocated,
 thereby keeping their memory cell throughout all program execution, while also having the same scope of
 visibility as automatic local variables. Hence whatever values the function puts into its static local
 variables during one call will remain the same whenever the function is called again.


