#pragma once
#include "Factory.h"
#include "Operations/headers/PushOperation.h"

class PushFactory : public Factory{
    Operations * createOperation(Command &command, Context &context);
};
