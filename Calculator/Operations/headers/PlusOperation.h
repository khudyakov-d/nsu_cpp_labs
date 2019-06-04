#pragma once
#include "Operations.h"

class PlusOperation : public Operations{
public:
    PlusOperation(Command &command, Context &context);
    void makeOperation();
  };

