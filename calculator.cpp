#include "calculator.h"

const std::string operation_symbols = "/*^#";
const std::vector<std::string> invalid_words{
  "nn", ".", "l", "u", "oo", "()", "b)", "o)", "(o"
};
const std::map<std::string, std::string> key_words{
    {"sqrt", "#"}
};

SYMBOL Calculator::whatIsThis(const char s)
{
    if(s >= '0' && s <= '9')
        return SYMBOL::NUMBER;
    if(s == '+' || s == '-')
        return SYMBOL::OPERATOR_PM;
    if(operation_symbols.find(s) != std::string::npos)
        return SYMBOL::OPERATOR_OTHER;
    if(s == ')') return SYMBOL::RIGHT_BRACE;
    if(s == '(') return SYMBOL::LEFT_BRACE;
    if(s == '.') return SYMBOL::DOT;
    if(s >= 'a' && s <= 'z')
        return SYMBOL::LETTER;
    return SYMBOL::UNKNOW;

}

bool Calculator::verify(std::string &&str)
{
    if(str.empty()) return false;
    bool resoult = true;
    for(auto& it: invalid_words){
        size_t pos = 0;
        while((pos = str.find(it, pos)) != std::string::npos){
            resoult = false;
            std::cout << "Invalid symbol: " << pos << " -> " << str.substr(pos, it.size()) << std::endl;
            pos += it.size();
        }
    }

    if(resoult != false){
        if(std::count(str.begin(), str.end(), '(') !=
                std::count(str.begin(), str.end(), ')')) resoult = false;
        if(str[0] == 'o') resoult = false;
        if(*str.rbegin() == 'o') resoult = false;
    }
    return resoult;
}

std::string Calculator::simplify(const std::string &&str)
{
    std::string resoult_str(str);
    std::for_each(key_words.begin(), key_words.end(), [&resoult_str](auto& pair){
        size_t pos;
        while((pos = resoult_str.find(pair.first)) != std::string::npos){
            resoult_str.replace(pos, pair.first.size(), pair.second);
        }
    });
    std::for_each(resoult_str.begin(), resoult_str.end(), [](char&s){ if(s != 'n') s = static_cast<char>(whatIsThis(s));});
    return resoult_str;
}

std::string Calculator::simplifyNumbers(const std::string &str, const Calculator::vector_pair &myStruct)
{
    std::string resoult_str(str);
    size_t n = 0;

    for(auto& it: myStruct){
        resoult_str.replace(it.first-n, it.second, "n");
        n += it.second-1;
    }
    return resoult_str;
}

Calculator::vector_pair Calculator::findNumbers(const std::string &str)
{
    vector_pair myStruct;
    if(str.empty()) return vector_pair();
    bool isNumber = false;
    size_t start_pos = 0;
    bool isDot = false;
    std::string resoult_str(str);
    std::for_each(resoult_str.begin(), resoult_str.end(),[](char& s){if(s >= '0' && s <= '9') s = 'n'; });
    for(size_t i = 0; i < resoult_str.size(); i++){
        if(resoult_str[i] == static_cast<char>(SYMBOL::NUMBER)){
            if(!isNumber) {isNumber = true; start_pos = i;}
        }else{
            if(resoult_str[i] == static_cast<char>(SYMBOL::DOT)){
                if(isNumber && !isDot) { isDot = true;}
                else
                    if(isDot && isNumber){
                        isDot = false; isNumber = false;
                        if(resoult_str[i-1] == '.'){
                            myStruct.push_back(std::make_pair(start_pos, i-start_pos-1));
                        }else{
                            myStruct.push_back(std::make_pair(start_pos, i-start_pos));
                    }
                    }
            }else{
                if(isNumber){
                    if(resoult_str[i-1] == '.')
                        myStruct.push_back(std::make_pair(start_pos, i-start_pos-1));
                    else
                        myStruct.push_back(std::make_pair(start_pos, i-start_pos));
                }
                isNumber = false;
                isDot = false;
            }
        }
    }
    if(isNumber){
        myStruct.push_back(std::make_pair(start_pos, resoult_str.size()-start_pos));
    }
    return myStruct;
}

bool Calculator::fullVerification(const std::string &str)
{
    return Calculator::verify(Calculator::simplify(Calculator::simplifyNumbers(str, Calculator::findNumbers(str))));
}

Number Calculator::calculate(const std::string &str)
{
    if(!Calculator::fullVerification(str)){
        // throw verification error
        throw std::runtime_error("class Calculator: Error to vecification!\n");
    }
    return Expression(nullptr, str).calculate();
}

Calculator::Calculator()
{

}
