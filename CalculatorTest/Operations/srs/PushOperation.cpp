#include "Operations/headers/PushOperation.h"
#include <sstream>

PushOperation::PushOperation(Command &command, Context &context):Operations(context) {
    command_ = command;
}

void PushOperation::makeOperation() {
    try{
        std::stringstream ss;
        ss << command_[1];

        double value = 0;

        ss >> value;

        if(ss.fail()) {
            throw InvalidInput("Invalid value for this operation");
        }
        else context_.push(std::stod(command_[1]));
    }
    catch (std::out_of_range & ex) {
        std::cout << "Value is out of the range of representable values" <<  ex.what();
    }
    catch (InvalidInput & ex) {
        if (context_.containsArg(command_[1])){
            context_.push(context_.topArg(command_[1]));
        }
        else{
            std::cout << "Invalid value for push" << ex.what();
            throw ex;
        }
    }
}

