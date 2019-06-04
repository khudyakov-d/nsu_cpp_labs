#pragma once
#include "Factory.h"

class MulFactory : public Factory{
public:
    Operations * createOperation(Command &command, Context &context);
};
