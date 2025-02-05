                                         # SimpleLang Compiler

This project implements a simple compiler for a custom language called **SimpleLang**. It processes a SimpleLang source code and generates an assembly output.

## Files in the Project

- **Lexical.c**: Contains code for lexical analysis (tokenizing the input).
- **Parsing.c**: Contains code for parsing tokens into an Abstract Syntax Tree (AST).
- **Codegen.c**: Contains code to generate assembly output from the AST.
- **Main.c**: The main driver of the program that reads the source file, processes it, and generates the assembly output.
- **input.slang**: A sample SimpleLang source code file.

## Sample Input (`input.slang`)

```plaintext
// Variable declaration 
int x;
int y; 
int z; 

// Assignment 
x = 10; 
y = 20; 
z = x + y; 

// Conditional 
if (z == 30) { 
    z = z + 1; 
}



# Compiling and Running the Program

Compile the program:

gcc -o compiler Lexical.c Parsing.c Codegen.c Main.c

Run the compiler:

./compiler

The generated assembly code will be written to output.asm.

x DB 0
y DB 0
z DB 0
MOV x, 10
MOV y, 20
MOV z, x
ADD z, y
CMP z, 30
JNZ END_IF
MOV z, z
ADD z, 1
END_IF:
