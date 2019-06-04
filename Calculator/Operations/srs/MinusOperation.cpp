#include "Operations/headers/MinusOperation.h"

void MinusOperation::makeOperation() {
    try{
         context_.push(context_.pop() - context_.pop());
    }
    catch(EmptyStack & ex) {
        std::cout << ex.what();
    }
}

MinusOperation::MinusOperation(Command &command, Context &context):Operations(context){
    command_ = command;
}