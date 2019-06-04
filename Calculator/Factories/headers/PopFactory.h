#pragma once
#include "Factory.h"
#include "Operations/headers/PopOperation.h"

class PopFactory : public Factory{
    Operations * createOperation(Command &command, Context &context);
};
