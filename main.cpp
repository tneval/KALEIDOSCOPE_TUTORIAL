#include "token.h"
#include "lexer.h"

int main()
{

    kaleidoscope::Token a(kaleidoscope::tok_eof);
    kaleidoscope::Token b(kaleidoscope::tok_number, 40);
    kaleidoscope::Token c(kaleidoscope::tok_identifier, "X");

    a.printToken();
    b.printToken();
    c.printToken();

    kaleidoscope::Lexer l;

    while(true){
        kaleidoscope::Token s = l.getToken();

        s.printToken();
    }

    

}