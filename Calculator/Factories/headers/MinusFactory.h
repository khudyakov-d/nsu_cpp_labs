#pragma once
#include "Factory.h"

class MinusFactory : public Factory{
public:
    Operations * createOperation(Command &command, Context &context);
};
