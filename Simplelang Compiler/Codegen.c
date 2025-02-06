#include "Parsing.c"

void generate_assembly() 
{   
    // writing the assembly instructions
    FILE *assemblyFile = fopen("output.asm", "w"); // Automatically generated once compile

    
    for (int index = 0; index < node_count; index++) 
    {
        if (strcmp(ast[index]->type, "DECLARATION") == 0) 
        {
            fprintf(assemblyFile, "%s DW 0\n", ast[index]->value);
        } 
        
        
        else if (strcmp(ast[index]->type, "ASSIGNMENT") == 0) 
        
        {
            fprintf(file, "MOV %s, %s\n", ast[index]->value, ast[index]->children[0]->value);
        } else if 
            
            (strcmp(ast[index]->type, "IF_STATEMENT") == 0) 
        
        {
            fprintf(assemblyFile, "CMP %s, 30\nJNZ SKIP_IF\n", ast[index]->children[0]->value);

            
            fprintf(assemblyFile, "MOV %s, %s\n", ast[index]->children[1]->children[0]->value,
                    ast[index]->children[1]->children[0]->children[0]->value);

            
            fprintf(assemblyFile, "SKIP_IF:\n");
        }
    }


    
    fclose(assemblyFile);
}
