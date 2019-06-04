#pragma once
#include "Operations.h"

class PushOperation : public Operations{
public:
    PushOperation(Command &command, Context &context);
    void makeOperation();
};


