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
int a;
int b; 
int c; 

// Assignment 
a = 10; 
b = 20; 
c = a + b; 

// Conditional 
if (c == 30) { 
    c = c + 1; 
}



# Compiling and Running the Program

Compile the program:

gcc -o compiler Lexical.c Parsing.c Codegen.c Main.c

Run the compiler:

./compiler

The generated assembly code will be written to output.asm.

a DB 0
b DB 0
c DB 0
MOV a, 10
MOV b, 20
MOV c, a
ADD c, b
CMP c, 30
JNZ END_IF
MOV c, c
ADD c, 1
END_IF:
