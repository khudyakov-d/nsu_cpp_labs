#pragma once
#include "Factory.h"
#include "Operations/headers/PrintOperation.h"

class PrintFactory : public Factory{
    Operations * createOperation(Command &command, Context &context);
};
