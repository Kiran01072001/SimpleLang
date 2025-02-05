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
    int i = 0, j = 0;
    while (code[i] != '\0') {
        if (isdigit(code[i])) {
            buffer[j++] = code[i];
            while (isdigit(code[++i])) buffer[j++] = code[i];
            buffer[j] = '\0';
            plus_token("NUMBER", buffer);
        } else if (isalpha(code[i])) {
            buffer[j++] = code[i];
            while (isalnum(code[++i])) buffer[j++] = code[i];
            buffer[j] = '\0';
            if (strcmp(buffer, "int") == 0) plus_token("INT", buffer);
            else if (strcmp(buffer, "if") == 0) plus_token("IF", buffer);
            else plus_token("IDENTIFIER", buffer);
        } else if (code[i] == '=') {
            if (code[i + 1] == '=') { plus_token("EQUAL", "=="); i++; }
            else plus_token("ASSIGN", "=");
        } else if
        // character is a plus symbol
        (code[i] == '+') plus_token("PLUS", "+");
        else if
        // character is a ;
        (code[i] == ';') plus_token("SEMICOLON", ";");
        else if
        //character is a { Lbrace
        (code[i] == '{') plus_token("LBRACE", "{");
        else if 
        //character is a } Rbrace
        (code[i] == '}') plus_token("RBRACE", "}");
        else if 
        // character is a (  Lparen
        (code[i] == '(') plus_token("LPAREN", "(");
        else if 
        // character is a ) Rparen
        (code[i] == ')') plus_token("RPAREN", ")");
        i++, j = 0;
    }
}
