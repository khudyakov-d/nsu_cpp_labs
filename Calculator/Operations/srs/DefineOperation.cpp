#include "Operations/headers/Operations.h"
#include "Operations/headers/DefineOperation.h"

void DefineOperation::makeOperation() {
    try{
       context_.setArg(command_[1],std::stod(command_[2]));

    }
    catch (std::out_of_range & ex) {
        std::cout << "Value is out of the range of representable values" <<  ex.what();
    }
    catch (std::invalid_argument & ex) {
        std::cout << "Invalid value for define" << ex.what();
    }
}

DefineOperation::DefineOperation(Command &command, Context &context):Operations(context){
    command_ = command;
}