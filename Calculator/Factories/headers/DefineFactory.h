#pragma once
#include "Factory.h"

class DefineFactory : public Factory{
public:
    Operations * createOperation(Command &command, Context &context);
};
