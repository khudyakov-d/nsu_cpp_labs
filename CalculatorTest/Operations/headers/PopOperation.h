#pragma once
#include "Operations.h"

class PopOperation : public Operations{
public:
    PopOperation(Command &command, Context &context);
    void makeOperation();
 };


