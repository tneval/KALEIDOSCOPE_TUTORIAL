#ifndef TOKEN_H
#define TOKEN_H

#include <string>

namespace kaleidoscope{

enum token_id {
    tok_eof = -1,

    // Commands
    tok_def = -2,
    tok_extern = -3,

    // Primary
    tok_identifier = -4,
    tok_number = -5,

    tok_undef,
};



class Token{
public:
    Token(){};
    Token(token_id id){
        id_ = id;
    };
    Token(token_id id, std::string id_string){
        id_ = id;
        identifierStr_ = id_string;
    };
    Token(token_id id, double num){
        id_ = id;
        numVal_ = num;
    }


    void printToken();
    void setType(token_id type);
    void setNumVal(double val);


private:
    token_id id_;
    std::string identifierStr_;
    double numVal_;
};



} // Namespace kaleidoscope

#endif