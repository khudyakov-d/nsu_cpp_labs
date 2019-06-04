#pragma once
#include "Operations.h"

class MinusOperation : public Operations{
public:
    MinusOperation(Command &command, Context &context);
    void makeOperation();
};

