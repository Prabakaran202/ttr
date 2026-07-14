#ifndef PARSER_H
#define PARSER_H

#include "lexer.h"

typedef enum {
    AST_PRINT,
    AST_ASSIGNMENT // புதியது: வேரியபிள் அசைன்மெண்ட்
} ASTNodeType;

typedef struct {
    ASTNodeType type;
    char value[256]; 
    
    // Variables-க்காக புதிதாகச் சேர்க்கப்பட்டவை
    char var_name[256]; // உதா: age
    char var_type[10];  // உதா: Num, Str
} ASTNode;

ASTNode parse();

#endif
