#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TOKENS 100

typedef struct {
    char type[20];
    char value[20];
} Token;

Token tokens[MAX_TOKENS];
int token_count = 0;

void add_token(const char *type, const char *value) {
    strcpy(tokens[token_count].type, type);
    strcpy(tokens[token_count].value, value);
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
            add_token("NUMBER", buffer);
        } else if (isalpha(code[i])) {
            buffer[j++] = code[i];
            while (isalnum(code[++i])) buffer[j++] = code[i];
            buffer[j] = '\0';
            if (strcmp(buffer, "int") == 0) add_token("INT", buffer);
            else if (strcmp(buffer, "if") == 0) add_token("IF", buffer);
            else add_token("IDENTIFIER", buffer);
        } else if (code[i] == '=') {
            if (code[i + 1] == '=') { add_token("EQUAL", "=="); i++; }
            else add_token("ASSIGN", "=");
        } else if (code[i] == '+') add_token("PLUS", "+");
        else if (code[i] == ';') add_token("SEMICOLON", ";");
        else if (code[i] == '{') add_token("LBRACE", "{");
        else if (code[i] == '}') add_token("RBRACE", "}");
        else if (code[i] == '(') add_token("LPAREN", "(");
        else if (code[i] == ')') add_token("RPAREN", ")");
        i++, j = 0;
    }
}
