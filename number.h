#ifndef NUMBER_H
#define NUMBER_H

#include <sstream>
#include <exception>
#include <boost/multiprecision/cpp_dec_float.hpp>
//#include <regex>

typedef boost::multiprecision::cpp_dec_float_50 type_of_value;
class Number{
private:
    type_of_value value;

    bool validate(const std::string &number);
public:
    Number();
    Number(const Number& obj);
    Number(const type_of_value value_);
    Number(const double obj);
    Number(const std::string &number, bool validate_on = true);

    type_of_value getValue() const;

    Number operator+(const Number& obj);
    Number operator-(const Number& obj);
    Number operator*(const Number& obj);
    Number operator/(const Number& obj);
    Number& operator =(const Number& obj);
    Number& operator =(const double obj);
    bool operator ==(type_of_value number);
    friend std::ostream &operator<<(std::ostream& os, Number& obj){ os << obj.getValue(); return os;}
    friend std::ostream &operator<<(std::ostream& os, Number&& obj){ os << obj.getValue(); return os;}

};

#endif // NUMBER_H
