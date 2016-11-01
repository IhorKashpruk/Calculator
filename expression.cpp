#include "expression.h"

Expression::Expression(Expression *parent_) : parent(parent_), str("") {}

Expression::Expression(Expression *parent_, const std::string &str_) : parent(parent_), str("")
{
    createTree(str_);
}

void Expression::createTree(const std::string &str)
{
    Expression* ptr = this;
    for(int i = 0; i < str.size(); i++){
        if(ptr == nullptr)
            throw std::runtime_error("class Expression. function createTree(...) NullPointerException!\n");
        ptr = ptr->addSymbol(str[i]);
    }
}

Expression *Expression::addSymbol(char s)
{
    if(s == '('){
        next.push_back(expr_ptr(new Expression(this)));
        str.push_back('&');
        return (*next.rbegin()).get();
    }
    else
        if(s == ')'){
            return parent;
        }
    str.push_back(s);
    return this;
}

std::string Expression::getFullStr() const
{
    std::string resolt_str = str;
    size_t pos;
    size_t n = 0;
    while((pos = resolt_str.find("&")) != std::string::npos){
        if(next.size() > n){
            resolt_str.replace(pos, 1, "("+next[n]->getFullStr()+")");
            n++;
        }
    }
    return resolt_str;
}

Number Expression::calculate()
{
    if(str.empty()) return 0.0;
    vector_pair number_pair = Calculator::findNumbers(str);
    std::vector<Number> numbers;
    if(str[0] == '-') numbers.push_back(0.0);
    for(int i = 0; i < number_pair.size(); i++){
        numbers.push_back(Number(str.substr(number_pair[i].first, number_pair[i].second)));
    }
    if(numbers.size() == 1)
        return numbers[0];
    std::vector<char> char_pair;
    std::string copy_str = Calculator::simplifyNumbers(str,number_pair);
    for(int i = 0; i < copy_str.size(); i++){
        if(copy_str[i] != 'n') char_pair.push_back(copy_str[i]);
    }

    int n = 0;
    for(int i = 0; i < char_pair.size(); i++){
        if(char_pair[i] == '&') {
            numbers.insert(numbers.begin()+i, next[n]->calculate());
            char_pair.erase(char_pair.begin()+i); i--;
            n++;
        }
        else{
            if(char_pair[i] == '#') numbers.insert(numbers.begin()+i,Number(0.0));
        }
    }
    OperationArray operArray;
    for(int i = 0; i < char_pair.size(); i++){
        operArray.addOperation(OperationFactory::make_operator(char_pair[i], numbers[i], numbers[i+1]));
    }

    return operArray.calculate();
}
