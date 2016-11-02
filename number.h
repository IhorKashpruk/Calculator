#ifndef NUMBER_H
#define NUMBER_H

#include <sstream>
#include <exception>
//#include <regex>

class Number{
private:
    double value;

    bool validate(const std::string &number);
public:
    Number();
    Number(const Number& obj);
    Number(const double value_);
    Number(const std::string &number, bool validate_on = true);

    double getValue() const;

    Number operator+(const Number& obj);
    Number operator-(const Number& obj);
    Number operator*(const Number& obj);
    Number operator/(const Number& obj);
    Number& operator =(const Number& obj);
    bool operator ==(double number);
    friend std::ostream &operator<<(std::ostream& os, Number& obj){ os << obj.getValue(); return os;}
    friend std::ostream &operator<<(std::ostream& os, Number&& obj){ os << obj.getValue(); return os;}

};

#endif // NUMBER_H
