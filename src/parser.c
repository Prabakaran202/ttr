#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../core/parser.h"

ASTNode parse() {
    ASTNode node;
    node.type = -1; 
    Token current_token = get_next_token();

    // 1. Print கமாண்டாக இருந்தால் (பழைய லாஜிக்)
    if (current_token.type == TOKEN_PRINT) {
        current_token = get_next_token(); 
        if (current_token.type == TOKEN_LPAREN) {
            current_token = get_next_token(); 
            if (current_token.type == TOKEN_STRING) {
                node.type = AST_PRINT;
                strcpy(node.value, current_token.value);
                get_next_token(); // Skip ')'
            }
        }
    } 
    // 2. வேரியபிளாக இருந்தால் (புதிய லாஜிக்)
    else if (current_token.type == TOKEN_IDENTIFIER) {
        strcpy(node.var_name, current_token.value); // வேரியபிள் பெயர் (உதா: age)
        
        current_token = get_next_token();
        if (current_token.type == TOKEN_ASSIGN) { // '=' வருகிறதா?
            
            current_token = get_next_token();
            node.type = AST_ASSIGNMENT;
            
            // அது நம்பரா? அப்போ 'Num' போடு!
            if (current_token.type == TOKEN_NUMBER) {
                strcpy(node.var_type, "Num");
                strcpy(node.value, current_token.value);
            } 
            // அது ஸ்ட்ரிங்கா? அப்போ 'Str' போடு!
            else if (current_token.type == TOKEN_STRING) {
                strcpy(node.var_type, "Str");
                sprintf(node.value, "\"%s\"", current_token.value); // Quotes சேர்க்கிறோம்
            }
        }
    }
    return node;
}
