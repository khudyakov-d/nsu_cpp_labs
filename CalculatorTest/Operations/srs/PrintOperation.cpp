#include "Operations/headers/PrintOperation.h"

PrintOperation::PrintOperation(Command &command, Context &context):Operations(context) {
    command_ = command;
}

void PrintOperation::makeOperation() {
    try{
        std::cout << context_.top() << "\n";
    }
    catch(EmptyStack & ex) {
        std::cout << ex.what();
        throw ex;
    }
}

