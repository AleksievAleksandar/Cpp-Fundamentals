#pragma once

#include <stack>
#include "Operation.h"
#include "InputInterpreter.h"
#include "CalculationEngine.h"

class MemoryStorage : public Operation
{
private:
	std::stack<int> memory;

public:
    void addOperand(int operand) override
    {
        this->memory.push(operand);
    }

    bool isCompleted() override
    {
        return false;
    }

    int getResult() override
    {
        int memoryTop = memory.top();
        this->memory.pop();
        return memoryTop;
    }
};
