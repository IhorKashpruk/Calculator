#ifndef OPERATION_H
#define OPERATION_H
#include <memory>
#include <stdexcept>
#include <cmath>
#include <vector>
#include "number.h"

#define MAX_PRIORITY 5
#define MIN_PRIORITY 0

// Interface
class Operation
{
protected:
    Number left;
    Number right;
    size_t priority;
public:
    Operation();
    Operation(const Operation& obj);
    Operation(const Number& l, const Number& r, size_t p);
    Number getLeft() const;
    Number getRight() const;
    size_t getPriority() const;

    void setLeft(const Number& l);
    void setRight(const Number& r);

    virtual Number calculate() = 0;
    Operation& operator =(const Operation& o);
};

// Classes
class operator_add : public Operation
{
public:
    operator_add(const Number& l, const Number& r);
    // Operation interface
    Number calculate();
};

class operator_sub : public Operation
{
public:
    operator_sub(const Number& l, const Number& r);
    // Operation interface
    Number calculate();
};

class operator_mul : public Operation
{
public:
    operator_mul(const Number& l, const Number& r);
    // Operation interface
    Number calculate();
};

class operator_share : public Operation
{
public:
    operator_share(const Number& l, const Number& r);
    // Operation interface
    Number calculate();
};

class operator_pow : public Operation
{
public:
    operator_pow(const Number& l, const Number& r);
    // Operation interface
    Number calculate();
};

class operator_sqrt : public Operation
{
public:
    operator_sqrt(const Number& o);
    // Operation interface
    Number calculate();
};

class OperationArray
{
private:
    std::vector<std::shared_ptr<Operation>> values;
public:
    OperationArray(){}
    void addOperation(Operation *o);
    Number calculate();
};

class OperationFactory{
private:
    OperationFactory(){}
public:
static Operation* make_operator(const char s, Number& obj1, Number& obj2){
    switch(s){
        case '+': return new operator_add(obj1, obj2);
        case '-': return new operator_sub(obj1, obj2);
        case '*': return new operator_mul(obj1, obj2);
        case '/': return new operator_share(obj1, obj2);
        case '^': return new operator_pow(obj1, obj2);
        case '#': return new operator_sqrt(obj2);
    }
    return nullptr;
}
};

#endif // OPERATION_H
