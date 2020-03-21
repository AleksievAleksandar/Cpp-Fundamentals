#pragma once

#include <memory>
#include "Operation.h"
#include "MemoryStorage.h"

class MemoryRecallOperation : public Operation
{
private:
	std::shared_ptr<MemoryStorage> memory;

public:
	MemoryRecallOperation(std::shared_ptr<MemoryStorage> memory) :
		memory(memory)
	{}

	void addOperand(int operand)
	{

	}

	bool isCompleted() override
	{
		return true;
	}

	int getResult() override
	{
		return this->memory->getResult();
	}
};
