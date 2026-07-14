#ifndef PARSER_H
#define PARSER_H

#include "lexer.h"

// AST-ல் (Abstract Syntax Tree) இருக்கும் நோடுகளின் வகைகள்
typedef enum {
    AST_PRINT
    // எதிர்காலத்தில் AST_ASSIGNMENT, AST_IF போன்றவற்றை இங்கே சேர்க்கலாம்
} ASTNodeType;

// ஒரு AST Node-ன் கட்டமைப்பு
typedef struct {
    ASTNodeType type;
    char value[256]; // உதா: "Hello" (பிரிண்ட் செய்ய வேண்டிய வார்த்தை)
} ASTNode;

// Parser ஃபங்ஷன்
ASTNode parse();

#endif
.
