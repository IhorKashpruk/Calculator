#include "number.h"

Number::Number(const std::string &number, bool validate_on)
{
    if(validate_on){
        if(!validate(number)){
            throw std::runtime_error("class Number. String(" + number + ") can't be converted to double!\n");
        }
    }
    std::stringstream ss;
    ss << number;
    ss >> value;
}

Number::Number()
{
    value = 0.0;
}

Number::Number(const Number &obj)
{
    this->value = obj.getValue();
}

Number::Number(const double value_)
{
    value = value_;
}


double Number::getValue() const
{
    return value;
}

Number Number::operator+(const Number &obj)
{
    return (this->value+obj.getValue());
}

Number Number::operator-(const Number &obj)
{
    return (this->value-obj.getValue());
}

Number Number::operator*(const Number &obj)
{
    return (this->value*obj.getValue());
}

Number Number::operator/(const Number &obj)
{
    return (this->value/obj.getValue());
}

Number &Number::operator =(const Number &obj)
{
    if(this != &obj){
        this->value = obj.getValue();
    }
    return *this;
}

bool Number::operator ==(double number)
{
    return value == number;
}

bool Number::validate(const std::string& number)
{
    if(number.empty()) return false;
    size_t pos_to_start = number[0] == '+' || number[0] == '-' ? 1 : 0;
    bool isDrow = false;
    bool isNumber_start = false;
    for(int i = pos_to_start; i < number.size();  i++){
        if(isdigit(number[i]) != 0){
            isNumber_start = true;
        }else{
            if(number[i] == '.'){
                if(!isNumber_start) return false;
                if(isDrow) return false;
                isDrow = true;
            }else
                return false;
        }
    }
    return true;
//    std::regex reg_number("((\\+|-)?[[:digit:]]+)(\\.(([[:digit:]]+)?))?");
//    return std::regex_match(number, reg_number);
}
