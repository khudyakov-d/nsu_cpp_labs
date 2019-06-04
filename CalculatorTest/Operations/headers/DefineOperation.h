#pragma once
#include "Operations.h"

class DefineOperation : public Operations{
public:
    DefineOperation(Command &command, Context &context);
    void makeOperation();
};

