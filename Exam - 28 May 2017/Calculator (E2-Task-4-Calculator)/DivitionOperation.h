#pragma once

#include "Operation.h"
#include <vector>

class DivitionOperation : public Operation
{
private:
    std::vector<int> operands;

public:
    void addOperand(int operand) override 
    {
        this->operands.push_back(operand);
    }

    bool isCompleted() override 
    {
        return this->operands.size() == 2;
    }

    int getResult() override
    {
        return this->operands[0] / operands[1];
    }
};
