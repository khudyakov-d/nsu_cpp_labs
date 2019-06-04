#pragma once
#include "Operations/headers/Operations.h"

class Factory
{
public:
    virtual Operations * createOperation(Command &command, Context &context) = 0;
    virtual ~Factory() = default;
};

