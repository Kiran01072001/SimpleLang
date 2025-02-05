#include "Lexical.c"

typedef struct ASTNode {
    char type[20];
    char value[20];
    struct ASTNode *children[2];
} ASTNode;

ASTNode *ast[MAX_TOKENS];
int ast_count = 0;

ASTNode *create_node(const char *type, const char *value) {
    ASTNode *node = (ASTNode *)malloc(sizeof(ASTNode));
    strcpy(node->type, type);
    strcpy(node->value, value);
    node->children[0] = node->children[1] = NULL;
    return node;
}

void parse() {
    int i = 0;
    while (i < token_count) {
        if (strcmp(tokens[i].type, "INT") == 0) {
            ast[ast_count++] = create_node("DECLARATION", tokens[i + 1].value);
            i += 2;
        } else if (strcmp(tokens[i].type, "IDENTIFIER") == 0 && strcmp(tokens[i + 1].type, "ASSIGN") == 0) {
            ASTNode *node = create_node("ASSIGNMENT", tokens[i].value);
            node->children[0] = create_node("EXPR", tokens[i + 2].value);
            ast[ast_count++] = node;
            i += 4;
        } else if (strcmp(tokens[i].type, "IF") == 0) {
            ASTNode *condition = create_node("CONDITION", tokens[i + 2].value);
            ASTNode *block = create_node("BLOCK", "");
            i += 4;
            while (strcmp(tokens[i].type, "RBRACE") != 0) {
                if (strcmp(tokens[i].type, "IDENTIFIER") == 0 && strcmp(tokens[i + 1].type, "ASSIGN") == 0) {
                    ASTNode *stmt = create_node("ASSIGNMENT", tokens[i].value);
                    stmt->children[0] = create_node("EXPR", tokens[i + 2].value);
                    block->children[0] = stmt;
                    i += 4;
                } else {
                    i++;
                }
            }
            ASTNode *if_stmt = create_node("IF_STATEMENT", "");
            if_stmt->children[0] = condition;
            if_stmt->children[1] = block;
            ast[ast_count++] = if_stmt;
            i++;
        } else {
            i++;
        }
    }
}
