#include "Operations/headers/MulOperation.h"

#include "Operations/headers/MulOperation.h"

void MulOperation::makeOperation() {
    try{
        context_.push(context_.pop() * context_.pop());
    }
    catch(EmptyStack & ex) {
        std::cout << ex.what();
    }
}

MulOperation::MulOperation(Command &command, Context &context):Operations(context){
    command_ = command;
}