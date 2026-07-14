#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../core/parser.h"

// பைத்தான் கோடைப் படித்து AST ஆக மாற்றும் ஃபங்ஷன்
ASTNode parse() {
    ASTNode node;
    node.type = -1; // ஆரம்பத்தில் எந்த வகையும் இல்லை (Default state)

    Token current_token = get_next_token();

    // 1. முதல் டோக்கன் 'print' ஆக இருக்கிறதா?
    if (current_token.type == TOKEN_PRINT) {
        
        current_token = get_next_token(); 
        // 2. அடுத்த டோக்கன் '(' ஆக இருக்கிறதா?
        if (current_token.type == TOKEN_LPAREN) {
            
            current_token = get_next_token(); 
            // 3. அடுத்த டோக்கன் String ("...") ஆக இருக்கிறதா?
            if (current_token.type == TOKEN_STRING) {
                node.type = AST_PRINT;
                strcpy(node.value, current_token.value); // String-ஐ AST-ல் சேமிக்கிறோம்
                
                current_token = get_next_token(); 
                // 4. கடைசி டோக்கன் ')' ஆக இருக்கிறதா?
                if (current_token.type == TOKEN_RPAREN) {
                    return node; // பக்கா! பிரிண்ட் கமாண்ட் சரியாக வந்துவிட்டது.
                } else {
                    printf("Syntax Error: ')' காணவில்லை!\n");
                }
            } else {
                printf("Syntax Error: print() உள்ளே String தேவை!\n");
            }
        } else {
            printf("Syntax Error: print-க்கு அடுத்து '(' காணவில்லை!\n");
        }
    }

    return node;
}
