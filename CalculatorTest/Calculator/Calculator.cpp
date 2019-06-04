#pragma once
#include "Calculator.h"

Calculator::Calculator() {
    context_ = Context();
    operation_ = nullptr;

    mapping["PUSH"]  = PUSH;
    mapping["POP"]    = POP;
    mapping["+"] = PLUS;
    mapping["-"]  = MINUS;
    mapping["*"] = MUL;
    mapping["/"]  = DIVISION;
    mapping["SQRT"]  = SQRT;
    mapping["PRINT"]  = PRINT;
    mapping["DEFINE"]  = DEFINE;
}

void Calculator::exec(Command &command){
   operation_ = Operations::createOperation(command, context_, mapping);
   if (operation_ != nullptr)
		operation_->makeOperation();
   delete(operation_);
}
