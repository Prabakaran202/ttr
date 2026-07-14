#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "../core/lexer.h"

// பைத்தான் கோடைப் படிப்பதற்கான வேரியபிள்கள்
static const char *source;
static int pos = 0;

// Lexer-ஐத் தொடங்கும் ஃபங்ஷன்
void init_lexer(const char *source_code) {
    source = source_code;
    pos = 0;
}

// அடுத்தடுத்த டோக்கன்களை எடுக்கும் ஃபங்ஷன்
Token get_next_token() {
    Token token;
    token.value[0] = '\0'; // ஆரம்பத்தில் மதிப்பை காலியாக்குகிறோம்

    // 1. இடைவெளிகளைத் தவிர்க்க (Skip Whitespaces / Newlines)
    while (source[pos] != '\0' && isspace(source[pos])) {
        pos++;
    }

    // 2. ஃபைல் முடிந்துவிட்டதா என்று பார்க்க (EOF)
    if (source[pos] == '\0') {
        token.type = TOKEN_EOF;
        return token;
    }

    // 3. அடைப்புக்குறிகள் (Parentheses)
    if (source[pos] == '(') {
        token.type = TOKEN_LPAREN;
        strcpy(token.value, "(");
        pos++;
        return token;
    }
    if (source[pos] == ')') {
        token.type = TOKEN_RPAREN;
        strcpy(token.value, ")");
        pos++;
        return token;
    }

    // 4. Strings ("..." அல்லது '...')
    if (source[pos] == '"' || source[pos] == '\'') {
        char quote = source[pos];
        pos++; // முதல் Quote-ஐத் தாண்ட
        int i = 0;
        while (source[pos] != '\0' && source[pos] != quote) {
            token.value[i++] = source[pos++];
        }
        token.value[i] = '\0'; // String-ஐ முடிக்க
        if (source[pos] == quote) pos++; // கடைசி Quote-ஐத் தாண்ட
        
        token.type = TOKEN_STRING;
        return token;
    }

    // 5. வார்த்தைகள் / Keywords (உதா: "print")
    if (isalpha(source[pos])) {
        int i = 0;
        while (source[pos] != '\0' && (isalnum(source[pos]) || source[pos] == '_')) {
            token.value[i++] = source[pos++];
        }
        token.value[i] = '\0';

        // அது "print" தானா என்று செக் செய்ய
        if (strcmp(token.value, "print") == 0) {
            token.type = TOKEN_PRINT;
        }
        return token;
    }

    // எதுவுமே பொருந்தவில்லை என்றால் அடுத்த எழுத்துக்குப் போக (Error Handling)
    pos++;
    token.type = TOKEN_EOF; 
    return token;
}
.
