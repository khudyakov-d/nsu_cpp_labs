#pragma once
#include "Factory.h"

class DivisionFactory : public Factory{
public:
    Operations * createOperation(Command &command, Context &context);
};
