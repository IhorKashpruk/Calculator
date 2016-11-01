#ifndef CALCULATOR_H
#define CALCULATOR_H
#include "number.h"
#include "expression.h"
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

/*Order of operations:  exp:    32*1-23-sqrt9+2^2
1) findNumbers(...)     ->      return vector<pair<size_t,size_t>> numer positions
2) simplifyNumbers(...) ->      n*n-sqrtn+n^n
3) simplify(...)        ->      nonb#nbnon
4) verify(...)          ->      return true or false
*/

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
extern const std::map<std::string, std::string> key_words;

class Calculator
{
typedef std::vector<std::pair<size_t, size_t>> vector_pair;
public:
    static SYMBOL whatIsThis(const char s);
    static bool verify(std::string&& str);
    static std::string simplify(const std::string&& str);
    static std::string simplifyNumbers(const std::string& str, const vector_pair& myStruct);
    static vector_pair findNumbers(const std::string& str);

    static bool fullVerification(const std::string& str);
    static Number calculate(const std::string& str);
private:
    Calculator();
};

#endif // CALCULATOR_H
