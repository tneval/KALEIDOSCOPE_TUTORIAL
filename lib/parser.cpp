#include "parser.h"
#include <iostream>

int gettok()
{
    // Store possible identifier here
    std::string identifier = "";

    // Store possible numerical value here
    double numval = 0;

    // Placeholder for first character
    char lastChar = ' ';

    // Get rid of the white spaces
    while(isspace(lastChar))
    {
        lastChar = getchar();
    }

    // We are getting 'define', 'extern', or 'identifier
    if(isalpha(lastChar))
    {   
        // Initialize the string
        identifier = identifier + lastChar;

        // Retrieve as long as we get characters/numbers
        while(true)
        {
            lastChar = getchar();
            if(isalnum(lastChar))
            {
                identifier = identifier + lastChar;
            }
            else
            {
                break;
            }
        }

        // Check type of token
        if(identifier == "def")
        {
            return tok_def;
        }
        else if(identifier == "extern")
        {
            return tok_extern;
        }
        else
        {
            return tok_identifier;
        }
    }
    else if(isdigit(lastChar) || lastChar == '.') // numbers
    {
        std::string numstr = "";

        numstr = numstr + lastChar;

        while(true)
        {
            lastChar = getchar();
            if(isdigit(lastChar) || lastChar == '.')
            {
                numstr = numstr + lastChar;
            }
            else
            {
                break;
            }
        }

        numval = strtod(numstr.c_str(),0);

        return tok_number;
    }
    else if(lastChar == '#') // Skip comments
    {
        while(lastChar != EOF && lastChar != '\n' && lastChar != '\r')
        {
            lastChar = getchar();
        }

        // Retrieve next token
        if(lastChar != EOF)
        {
            return gettok();
        }
        else
        {
            return tok_eof;
        }
    }
}