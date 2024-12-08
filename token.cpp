#include "token.h"
#include <iostream>

namespace kaleidoscope{


void Token::printToken()
{
    std::string type;

    if(id_ == tok_eof){
        type = "tok_eof";
    }else if(id_ == tok_def){
        type = "tok_def";
    }else if(id_ == tok_extern){
        type = "tok_extern";
    }else if(id_ == tok_identifier){
        type = "tok_identifier: " + this->identifierStr_;
    }else if(id_ == tok_number){
        type = "tok_number: " + std::to_string(this->numVal_);
    }else{
        type = "UNDEFINED";
    }

    std::cout << type << std::endl;
}

void Token::setType(token_id type)
{
    this->id_= type;
}

void Token::setNumVal(double val)
{
    this->numVal_ = val;
}

}




