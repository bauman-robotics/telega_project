#ifndef PARSER_H
#define PARSER_H

#include <string>
#include <vector>
#include <cmath>
#include <cctype>
#include <cstring>
#include <stdexcept>
#include <iostream>

struct Expression;

class Parser {
public:
        explicit Parser(const char* input) : input(input) {int CountTime=0;}
        Expression parse();
        int CountTime=0;
private:
        std::string parse_token(/*int CountTime*/);
        Expression parse_simple_expression();
        Expression parse_binary_expression(int min_priority);

        const char* input;
};

double Calculator(const char* input, int CountTime);
double eval(const Expression& e);

#endif // PARSER_H
