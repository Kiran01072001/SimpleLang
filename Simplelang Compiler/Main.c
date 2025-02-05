#include "Codegen.c"

void read_file(const char *filename, char *buffer) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error opening file.\n");
        exit(1);
    }
    fread(buffer, sizeof(char), 1000, file);
    fclose(file);
}

int main() {
    char code[1000];
    read_file("input.slang", code);
    tokenize(code);
    parse();
    generate_assembly();
    printf("Assembly code generated in output.asm\n");
    return 0;
}



