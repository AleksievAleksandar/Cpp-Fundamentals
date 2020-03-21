#pragma once

#include <memory>

#include "InputInterpreter.h"
#include "CalculationEngine.h"
#include "ExtendedInterpreter.h"

std::shared_ptr<InputInterpreter> buildInterpreter(CalculationEngine& engine) 
{
    return std::make_shared<ExtendedInterpreter>(engine);
}

