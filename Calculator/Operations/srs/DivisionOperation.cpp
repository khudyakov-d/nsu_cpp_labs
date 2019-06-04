#include "Operations/headers/DivisionOperation.h"

void DivisionOperation::makeOperation() {
    double val1, val2;
    try{
            val1 = context_.pop();
            val2 = context_.pop();
            if (val2 == 0) throw ZeroDivision("Division by zero");
            context_.push(val1 / val2);
    }
    catch(EmptyStack & ex) {
        std::cout << ex.what();
    }
    catch(ZeroDivision & ex) {
        std::cout << ex.what();
    }
}

DivisionOperation::DivisionOperation(Command &command, Context &context):Operations(context){
    command_ = command;
}