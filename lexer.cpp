#include "lexer.h"
#include <iostream>

namespace kaleidoscope{

Token Lexer::getToken(){

    Token t;

    std::string tok_string;

    int lastChar = ' ';

    // Remove the whitespace
    while(isspace(lastChar)){
        lastChar = getchar();
    }

    // Starts with character
    if(isalpha(lastChar)){
        tok_string = lastChar;
        lastChar = getchar();

        while(isalnum(lastChar)){
            tok_string = tok_string + static_cast<char>(lastChar);
            lastChar = getchar();
        }

        if(tok_string == "def"){
            t.setType(tok_def);
        }else if(tok_string == "extern"){
            t.setType(tok_extern);
        }else{
            t.setType(tok_identifier);
        }

        return t;
    }

    if(isdigit(lastChar) || lastChar == '.'){

        tok_string = lastChar;
        lastChar = getchar();

        while(isdigit(lastChar) || lastChar == '.'){
            tok_string = tok_string + static_cast<char>(lastChar);
            lastChar = getchar();
        }

        t.setType(tok_number);

        double numVal = strtod(tok_string.c_str(),0);
        t.setNumVal(numVal);

        return t;
    }

    // Comments
    if(lastChar == '#'){
        do
            lastChar = getchar();
        while (lastChar != EOF && lastChar != '\n' && lastChar != '\r');

        if(lastChar != EOF){
            return getToken();
        }

    }

    if (lastChar == EOF){
        t.setType(tok_eof);
        return t;
    }
    
    int thisChar = lastChar;
    lastChar = getchar();

    t.setType(tok_undef);

    return t;
}

}
