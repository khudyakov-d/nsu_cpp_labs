#pragma once
#include "Factory.h"
#include "Operations/headers/SqrtOperation.h"

class SqrtFactory : public Factory{
    Operations * createOperation(Command &command, Context &context);
};
