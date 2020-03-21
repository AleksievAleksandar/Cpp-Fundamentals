#pragma once

#include <memory>
#include "InputInterpreter.h"
#include "DivitionOperation.h"
#include "MemoryStorage.h"
#include "CalculationEngine.h"
#include "MemoryRecallOperation.h"

class ExtendedInterpreter : public InputInterpreter
{
private:
	std::shared_ptr<MemoryStorage> memory;

public:
	ExtendedInterpreter(CalculationEngine& engine) :
		InputInterpreter(engine)
	{}

	std::shared_ptr<Operation> getOperation(std::string operation) override
	{
		if (operation == "/")
		{
			return std::make_shared<DivitionOperation>();
		}
		else if (operation == "ms")
		{
			if (!memory)
			{
				memory = std::make_shared<MemoryStorage>();
			}
			return this->memory;
		}
		else if (operation == "mr")
		{
			return std::make_shared<MemoryRecallOperation>(this->memory);
		}
		else
		{
			return InputInterpreter::getOperation(operation);
		}
	}

};
