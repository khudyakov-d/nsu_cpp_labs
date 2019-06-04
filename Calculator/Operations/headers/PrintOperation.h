#pragma once
#include "Operations.h"

class PrintOperation : public Operations{
public:
    PrintOperation(Command &command, Context &context);
    void makeOperation();
};
