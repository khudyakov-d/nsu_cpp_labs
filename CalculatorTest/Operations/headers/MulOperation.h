#pragma once
#include "Operations.h"

class MulOperation : public Operations{
public:
    MulOperation(Command &command, Context &context);
    void makeOperation();
};

