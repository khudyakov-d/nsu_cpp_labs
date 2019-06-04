#pragma once
#include "Operations/headers/Operations.h"

class Calculator {
public:
    Calculator();
    void exec(Command &command);

private:
    Mapping mapping;
    Context context_;
    Operations * operation_;
};
