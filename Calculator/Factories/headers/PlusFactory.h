#pragma once
#include "Factory.h"
#include "Operations/headers/PlusOperation.h"

class PlusFactory : public Factory{
    Operations * createOperation(Command &command, Context &context);
};
