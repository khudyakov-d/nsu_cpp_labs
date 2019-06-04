#pragma once
#include "Operations.h"

class DivisionOperation : public Operations{
public:
    DivisionOperation(Command &command, Context &context);
    void makeOperation();
};

