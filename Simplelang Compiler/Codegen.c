#include "Parsing.c"

void generate_assembly() {
    FILE *file = fopen("output.asm", "w");
    for (int i = 0; i < ast_count; i++) {
        if (strcmp(ast[i]->type, "DECLARATION") == 0) {
            fprintf(file, "%s DB 0\n", ast[i]->value);
        } else if (strcmp(ast[i]->type, "ASSIGNMENT") == 0) {
            fprintf(file, "MOV %s, %s\n", ast[i]->value, ast[i]->children[0]->value);
        } else if (strcmp(ast[i]->type, "IF_STATEMENT") == 0) {
            fprintf(file, "CMP %s, 30\nJNZ END_IF\n", ast[i]->children[0]->value);
            fprintf(file, "MOV %s, %s\n", ast[i]->children[1]->children[0]->value,
                    ast[i]->children[1]->children[0]->children[0]->value);
            fprintf(file, "END_IF:\n");
        }
    }
    fclose(file);
}
