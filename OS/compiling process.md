```User writes a program in C language (high-level language). The C compiler, compiles
the program and translates it to assembly program (low-level language). An assembler 
then translates the assembly program into machine code (object). A linker tool is 
used to link all the parts of the program together for execution (executable machine code)
. A loader loads all of them into memory and then the program is executed.

Before diving straight into the concepts of compilers, we should understand a 
few other tools that work closely with compilers.
Preprocessor

A preprocessor, generally considered as a part of compiler, is a tool that
produces input for compilers. It deals with macro-processing, augmentation, 
file inclusion, language extension, etc.
```


__Interpreter__
An interpreter, like a compiler, translates high-level language into low-level
machine language. The difference lies in the way they read the source code or 
input. A compiler reads the whole source code at once, creates tokens, checks 
semantics, generates intermediate code, executes the whole program and may 
involve many passes. In contrast, an interpreter reads a statement from the
input, converts it to an intermediate code, executes it, then takes the next
statement in sequence. If an error occurs, an interpreter stops execution and
reports it. whereas a compiler reads the whole program even if it encounters 
several errors.


__Assembler__
An assembler translates assembly language programs into machine code.The output 
of an assembler is called an object file, which contains a combination of machine 
instructions as well as the data required to place these instructions in memory.


__Linker__
Linker is a computer program that links and merges various object files
together in order to make an executable file. All these files might have been 
compiled by separate assemblers. The major task of a linker is to search and
locate referenced module/routines in a program and to determine the memory location 
where these codes will be loaded, making the program instruction to have absolute
references.


__Loader__
Loader is a part of operating system and is responsible for loading executable 
files into memory and execute them. It calculates the size of a program (instructions and data) 
and creates memory space for it. It initializes various registers to initiate execution.


__Cross-compiler__
A compiler that runs on platform (A) and is capable of generating executable
code for platform (B) is called a cross-compiler.


__Source-to-source Compiler__
A compiler that takes the source code of one programming language and translates 
it into the source code of another programming language is called a source-to-source compiler.

```
Source code is the C program that you write in your editor and save with a ‘ .C ‘
extension. Which is un-compiled (when written for the first time or whenever a 
change is made in it and saved).

Object code is the output of a compiler after it processes the source code.
The object code is usually a machine code, also called a machine language, 
which can be understood directly by a specific type of CPU (central processing unit),
such as x86 (i.e., Intel-compatible) or PowerPC. However, some compilers are designed
to convert source code into an assembly language or some other another programming 
language. An assembly language is a human-readable notation using the mnemonics 
(mnemonicis a symbolic name for a single executable machine language instruction
called an opcode) in the ISA ( Instruction Set Architecture) of that particular CPU .

Executable (also called the Binary) is the output of a linker after it processes
the object code. A machine code file can be immediately executable (i.e., runnable as a program)
, or it might require linking with other object code files (e.g. libraries)
to produce a complete executable program.
```

__What is the Difference Between Static and Dynamic Linking__

The main difference between static and dynamic linking is that static linking copies 
all library modules used in the program into the final executable file at the final
step of the compilation while, in dynamic linking, the linking occurs at run time
when both executable files and libraries are placed in the memory.

Generally, a computer program is a sequence of steps in a programming language 
that instructs the computer or the CPU to perform a certain task. Even though
the programmer understands this program, the computer does not. Therefore, it 
is necessary to convert the source code to machine code. Also, this program might 
require other programs or libraries. In those cases, it is necessary to bring
those programs or libraries together with this program to execute it. Thus, 
linking is the process of combining external programs with the programmer’s 
program to execute it successfully. In overall, there are two linking mechanisms
as the static and dynamic linking.

__static linking__
Static linking copies all the libraries required for the program into the final
executable file. The linker performs this task, and it is the last step of compilation.
The linker combines the relevant libraries with the program code to resolve external
references. Finally, the linker generates an executable file suitable for loading into
memory. The final statistically linked file contains the calling program and called
programs. Generally, these files are large because they are connected with other files.

Difference Between Static and Dynamic LinkingAssume that there are some changes in the
external programs. In that case, it is necessary to recompile and re-link again. 
Otherwise, the existing executable file does not reflect these changes. Furthermore,
in statistical linking, all the modules and libraries are available as a single
executable module. Therefore, this linking is faster and does not cause compatibility issues.

What is Dynamic Linking
In dynamic linking, the names of the external libraries /shared libraries are 
copied into the final executable; thus, the real linking occurs at run time when
the executable file and libraries load to the memory. The operating system performs
dynamic linking. Generally, there is only one copy of a shared library is in 
the memory. Therefore, the size of the executable file is lower. It is possible
to update and recompile the external libraries. Moreover, if the shared library
code is already available in memory, there will be less load time.

Usually, in dynamic linking, it is better to have a compatible library. 
If there is a modification in the library, the application has to find a way 
to make it compatible with the new version of the library. Additionally,
removing the library can cause the program not to work further.

Difference Between Static and Dynamic Linking
Definition
Static linking is the process of copying all library modules used in the program 
into the final executable image. In contrast, dynamic linking is the process of
loading the external shared libraries into the program and then binds those shared
libraries dynamically to the program. Thus, this is the main difference between
static linking and dynamic linking.

Occurrence
Moreover, static linking is the last step of compilation, while dynamic linking 
occurs at run time.

File size
While statistically linked files are larger in size, dynamically linked files are
smaller in size.

Load time
Besides, static linking takes constant load time while dynamic linking takes less 
load time. Hence, this is another difference between static linking and dynamic linking.

Compatibility
Furthermore, there will be no compatibility issues with static linking. On the
other hand, there will be compatibility issues with dynamic linking.

Conclusion
In brief, static and dynamic linking are two linking mechanisms. The main difference
between static and dynamic linking is that static linking copies all library modules
used in the program into the final executable file at the final step of the compilation 
while in dynamic linking, the linking occurs at run time when both executable files and libraries are placed in the memory.
