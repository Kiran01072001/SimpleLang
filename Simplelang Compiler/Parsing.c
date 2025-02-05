#include "Lexical.c"

typedef struct ASTNode {
    char type[20];
    char value[20];
    struct ASTNode *children[2];
} ASTNode;

ASTNode *ast[MAX_TOKENS];
int ast_count = 0;

ASTNode *create_ast_node(const char *type, const char *value)
{
    ASTNode *node = (ASTNode *)malloc(sizeof(ASTNode));
    strcpy(node->type, type);
    strcpy(node->value, value);
    node->children[0] = node->children[1] = NULL;
    return node;
}

void parse() 

{
    int index = 0;
    while (index < token_count)
        
    {
        if (strcmp(tokens[index].type, "INT") == 0) 
        
        
        
        {
            ast[node_count++] = create_ast_node("DECLARATION", tokens[index + 1].value);
            index += 2;
        } 
        
        else if (strcmp(tokens[index].type, "IDENTIFIER") == 0 && strcmp(tokens[index + 1].type, "ASSIGN") == 0)
        {
            ASTNode *node = create_ast_node("ASSIGNMENT", tokens[index].value);
            node->children[0] = create_ast_node("EXPR", tokens[index + 2].value);
            ast[node_count++] = node;
            index += 4;
        } 
        
        else if (strcmp(tokens[index].type, "IF") == 0) 
        
        {
            ASTNode *condition = create_ast_node("CONDITION", tokens[index + 2].value);
            ASTNode *block = create_ast_node("BLOCK", "");
            index += 4;
            while (strcmp(tokens[index].type, "RBRACE") != 0) 
            
            
            {
                if (strcmp(tokens[index].type, "IDENTIFIER") == 0 && strcmp(tokens[index + 1].type, "ASSIGN") == 0)
                {
                    ASTNode *stmt = create_ast_node("ASSIGNMENT", tokens[index].value);
                    stmt->children[0] = create_ast_node("EXPR", tokens[index + 2].value);
                    block->children[0] = stmt;
                    index += 4;
                }
                
                else
                
                {
                    index++;
                }
            }
            ASTNode *if_stmt = create_ast_node("IF_STATEMENT", "");
            if_stmt->children[0] = condition;
            
            if_stmt->children[1] = block;
            ast[ast_count++] = if_stmt;
            index++;
        } else 
        
        {
            index++;
        }
    }
}
