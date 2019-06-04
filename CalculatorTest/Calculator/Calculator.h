#pragma once
#include "Operations/headers/Operations.h"

class Calculator {
public:
    Calculator();
    void exec(Command &command);
    Context getContext(){
        return context_;
    }

private:
    Mapping mapping;
    Context context_;
    Operations * operation_;
};
