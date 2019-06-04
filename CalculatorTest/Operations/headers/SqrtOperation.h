#pragma once
#include "Operations.h"

class SqrtOperation : public Operations{
public:
    SqrtOperation(Command &command, Context &context);
    void makeOperation();
};


