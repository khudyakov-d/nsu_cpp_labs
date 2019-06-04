#include "Operations/headers/PlusOperation.h"

PlusOperation::PlusOperation(Command &command, Context &context):Operations(context) {
    command_ = command;
}

void PlusOperation::makeOperation() {
    try{
        context_.push(context_.pop() + context_.pop());
    }
    catch(EmptyStack & ex) {
        std::cout << ex.what();
        throw ex;
    }
}

