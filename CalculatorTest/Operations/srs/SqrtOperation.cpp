#include "Operations/headers/SqrtOperation.h"
#include <math.h>

void SqrtOperation::makeOperation() {
    try{
        context_.push(std::sqrt(context_.pop()));
    }
    catch(EmptyStack & ex) {
        std::cout << ex.what();
    }
}

SqrtOperation::SqrtOperation(Command &command, Context &context):Operations(context) {
    command_ = command;
}