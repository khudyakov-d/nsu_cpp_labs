#include "Operations/headers/PopOperation.h"

PopOperation::PopOperation(Command &command, Context &context):Operations(context) {
    command_ = command;
}

void PopOperation::makeOperation() {
    try{
        context_.pop();
    }
    catch(EmptyStack & ex) {
        std::cout << ex.what();
        throw ex;
    }
}

