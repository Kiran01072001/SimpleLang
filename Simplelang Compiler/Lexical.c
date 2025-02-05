#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// We can define maximum number of tokens as per require.

#define MAX_TOKENS 120

typedef struct 
{
    char type[25];
    char value[25];
} Token;

Token tokens[MAX_TOKENS]; // Array for store tokens

int token_count = 0;

void plus_token(const char *type, const char *value) 
{
    strncpy(tokens[token_count].type, type);
    
    strncpy(tokens[token_count].value, value);
    token_count++;
}

void tokenize(const char *code) {
    char buffer[20];
    int index = 0, j = 0;
    while (code[index] != '\0') {
        if (isdigit(code[index])) {
            buffer[j++] = code[index];
            while (isdigit(code[++index])) buffer[j++] = code[index];
            buffer[j] = '\0';
            plus_token("NUMBER", buffer);
        } else if (isalpha(code[index])) {
            buffer[j++] = code[index];
            while (isalnum(code[++index])) buffer[j++] = code[index];
            buffer[j] = '\0';
            if (strcmp(buffer, "int") == 0) plus_token("INT", buffer);
            else if (strcmp(buffer, "if") == 0) plus_token("IF", buffer);
            else plus_token("IDENTIFIER", buffer);
        } else if (code[index] == '=') {
            if (code[index + 1] == '=') { plus_token("EQUAL", "=="); index++; }
            else plus_token("ASSIGN", "=");
        } else if
        // character is a plus symbol
        (code[index] == '+') plus_token("PLUS", "+");
        else if
        // character is a ;
        (code[index] == ';') plus_token("SEMICOLON", ";");
        else if
        //character is a { Lbrace
        (code[index] == '{') plus_token("LBRACE", "{");
        else if 
        //character is a } Rbrace
        (code[index] == '}') plus_token("RBRACE", "}");
        else if 
        // character is a (  Lparen
        (code[index] == '(') plus_token("LPAREN", "(");
        else if 
        // character is a ) Rparen
        (code[index] == ')') plus_token("RPAREN", ")");
        index++, j = 0;
    }
}
