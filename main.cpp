#include <iostream>
#include <sstream>
#include "calculator.h"
#include "expression.h"
#include "number.h"
#include "operation.h"

int main(int argc, char *argv[])
{

    std::string str;
    std::cout.precision(std::numeric_limits<boost::multiprecision::cpp_dec_float_50>::digits10);
    std::cout << "\nEnter expression('quit' to exit): ";
    std::cin >> str;
    while(str != "quit"){
        try {
            std::cout << "Result: " << Calculator::calculate(str) << std::endl
                      << "Enter expression: ";
            std::cin >> str;

        } catch (std::runtime_error& err) {
            std::cout << err.what();
            std::cout << "Enter new expression: ";
            std::cin >> str;
        }
    }

    return 0;
}
