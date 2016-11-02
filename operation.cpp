#include "operation.h"

Operation::Operation() : priority(0){}

Operation::Operation(const Operation &obj)
{
    this->left = obj.getLeft();
    this->right = obj.getRight();
}

Operation::Operation(const Number &l, const Number &r, size_t p) : left(l), right(r), priority(p){}

Number Operation::getLeft() const { return left; }

Number Operation::getRight() const { return right; }

size_t Operation::getPriority() const { return priority; }

void Operation::setLeft(const Number &l) { left = l; }

void Operation::setRight(const Number &r) { right = r; }

Operation &Operation::operator =(const Operation &o){
    if(this != &o){
        this->left = o.getLeft();
        this->right = o.getRight();
    }
    return *this;
}


// Class operator_add
operator_add::operator_add(const Number &l, const Number &r) : Operation(l, r, 3){}
Number operator_add::calculate(){ return left+right; }

// Class operator_sub
operator_sub::operator_sub(const Number &l, const Number &r) : Operation(l, r, 3){}
Number operator_sub::calculate(){ return left-right; }

// Class operator_mul
operator_mul::operator_mul(const Number &l, const Number &r) : Operation(l, r, 4){}
Number operator_mul::calculate(){ return left*right; }

// Class operator_share
operator_share::operator_share(const Number &l, const Number &r) : Operation(l, r, 4){}
Number operator_share::calculate(){
    if(right == 0.0)
        throw std::runtime_error("class operator_share. Error share to 0!\n");
    return left/right;
}

// Class operator_pow
operator_pow::operator_pow(const Number &l, const Number &r) : Operation(l, r, 5){}
Number operator_pow::calculate(){ return Number(pow(left.getValue(), right.getValue())); }

// Class operator_sqrt
operator_sqrt::operator_sqrt(const Number &o) : Operation(Number(0.0), o, 5){}
Number operator_sqrt::calculate(){ return Number(sqrt(right.getValue())); }

// Class OperatorArray
void OperationArray::addOperation(Operation *o){ values.push_back(std::shared_ptr<Operation>(o));}

Number OperationArray::calculate()
{
    auto copy_ptr = values;
    Number n;
    for(int i = MAX_PRIORITY; i >= MIN_PRIORITY; i--){
        for(int j = 0; j < copy_ptr.size(); j++){
            if(copy_ptr[j]->getPriority() == i){
                n = copy_ptr[j]->calculate();
                if(j != 0)
                    copy_ptr[j-1]->setRight(n);
                if(j != copy_ptr.size()-1)
                    copy_ptr[j+1]->setLeft(n);
                copy_ptr.erase(copy_ptr.begin()+j);
                j--;
            }
        }
    }
    return n;
}

