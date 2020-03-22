#include "parser.h"
#include "qdebug.h"

//Разбор введенной функции на числа, унарные/бинарные операторы

struct Expression {
    Expression(std::string token) : token(token) {}
        Expression(std::string token, Expression a) : token(token), args{ a } {}
        Expression(std::string token, Expression a, Expression b) : token(token), args{ a, b } {}

        std::string token;
        std::vector<Expression> args;
};

int CountTime=0;

std::string Parser::parse_token() {  //парсинг чисел

        while (std::isspace(*input)) ++input;

        if (std::isdigit(*input)) {
                std::string number;
                while (std::isdigit(*input) || *input == '.') number.push_back(*input++);
                return number;
        }

        static const std::string tokens[] =
        { "+", "-", "**", "^", "*", "/", "mod", "abs", "sin", "cos", "(", ")", "t", };
        for (auto& t : tokens) {
                if (std::strncmp(input, t.c_str(), t.size()) == 0) {
                        input += t.size();
                        return t;
                }
        }

        return "";
}

Expression Parser::parse_simple_expression() {  //парсинг унарных выражений
        auto token = parse_token();
        if (token.empty()) throw std::runtime_error("Invalid input");

        if (token == "(") {
                auto result = parse();
                if (parse_token() != ")") throw std::runtime_error("Expected ')'");
                return result;
        }

        if (std::isdigit(token[0]))
                return Expression(token);

        return Expression(token, parse_simple_expression());
}

int get_priority(const std::string& binary_op) {
        if (binary_op == "t") return 1;
        if (binary_op == "+") return 1;
        if (binary_op == "-") return 1;
        if (binary_op == "*") return 2;
        if (binary_op == "/") return 2;
        if (binary_op == "mod") return 2;
        if (binary_op == "**") return 3;
        if (binary_op == "^") return 3;

        return 0;
}

Expression Parser::parse_binary_expression(int min_priority) {  //парсинг бинарных выражений
        auto left_expr = parse_simple_expression();

        for (;;) {
                auto op = parse_token();
                auto priority = get_priority(op);
                if (priority <= min_priority) {
                        input -= op.size();
                        return left_expr;
                }

                auto right_expr = parse_binary_expression(priority);
                left_expr = Expression(op, left_expr, right_expr);
        }
}

Expression Parser::parse() {
        return parse_binary_expression(0);
}

double eval(const Expression& e) { //вычислитель результата операции
        switch (e.args.size()) {
        case 2: {
                auto a = eval(e.args[0]);
                auto b = eval(e.args[1]);
                if (e.token == "+") return a + b;
                if (e.token == "-") return a - b;
                if (e.token == "*") return a * b;
                if (e.token == "/") return a / b;
                if (e.token == "**") return pow(a, b);
                if (e.token == "mod") return (int)a % (int)b;
                if (e.token == "^") return pow(a, b);
                throw std::runtime_error("Unknown binary operator");
        }

        case 1: {
                auto a = eval(e.args[0]);
                if (e.token == "+") return +a;
                if (e.token == "-") return -a;
                if (e.token == "abs") return abs(a);
                if (e.token == "sin") return sin(a);
                if (e.token == "cos") return cos(a);
                if (e.token == "t") return CountTime;
                throw std::runtime_error("Unknown unary operator");
        }

        case 0:
                return strtod(e.token.c_str(), nullptr);
        }

        throw std::runtime_error("Unknown expression type");
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int errors;

double Calculator(const char* input, int GetCountTime) { //вычислитель результата ввода

    CountTime=GetCountTime;
    Parser p(input);
                   auto result = eval(p.parse());
                   qDebug() << " got " << result << '\n';
    return result;
}


