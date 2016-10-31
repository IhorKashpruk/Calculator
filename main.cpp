#include "calculator.h"
#include "expression.h"
#include "number.h"
#include <sstream>
#include "operation.h"
#include <unistd.h>

typedef std::vector<std::pair<size_t, size_t>> vector_pair;

template<typename T>
bool get(std::stringstream& ss, T& obj){
    ss >> obj;
    return !ss.fail();
}

int main(int argc, char *argv[])
{

    std::string str = "1+1";
    while(str != "quit"){
        Expression ex(nullptr, str);
          std::cout << ex.calculate() << std::endl;
        std::cin >> str;
    }




//    std::string str = "2+32*(1-45*(3+2))-23";

//    std::shared_ptr<Expression> ptr = nullptr;

//    std::shared_ptr<Expression> expr(new Expression(ptr));


//    ptr = expr->addNumber("2");
//    ptr = ptr->addOperation('+');
//    ptr = ptr->addNumber("32");
//    ptr = ptr->addOperation('*');
//    ptr = ptr->addOperation('(');
//    ptr = ptr->addNumber("1");
//    ptr = ptr->addOperation('-');
//    ptr = ptr->addNumber("45");
//    ptr = ptr->addOperation('*');
//    ptr = ptr->addOperation('(');
//    ptr = ptr->addNumber("3");
//    ptr = ptr->addOperation('+');
//    ptr = ptr->addNumber("2");
//    ptr = ptr->addOperation(')');
//    ptr = ptr->addOperation(')');
//    ptr = ptr->addOperation('-');
//    ptr = ptr->addNumber("23");

//    std::cout << expr->toString() << std::endl
//              << ptr->next.size();

    return 0;
}
