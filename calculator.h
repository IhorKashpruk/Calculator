#ifndef CALCULATOR_H
#define CALCULATOR_H
#include <iostream>
#include <vector>
#include <algorithm>


enum class SYMBOL : char{
    NUMBER          = 'n',  // 3.4, 3 etc.
    LEFT_BRACE      = '(',  // (
    RIGHT_BRACE     = ')',  // )
    DOT             = '.',  // .
    OPERATOR_PM     = 'b',  // +-
    OPERATOR_OTHER  = 'o',  // /*^#
    LETTER          = 'l',  // a-z
    UNKNOW          = 'u'   // other symbols
};

extern const std::string operation_symbols;
extern const std::vector<std::string> invalid_words;

class Calculator
{
typedef std::vector<std::pair<size_t, size_t>> vector_pair;
public:
    static SYMBOL whatIsThis(const char s);
    static void verify(std::string& str);
    static std::string simplify(const std::string& str);
    static std::string simplifyNumbers(const std::string& str, const vector_pair& myStruct);
    static vector_pair findNumbers(const std::string& str);

    Calculator();
};

#endif // CALCULATOR_H
