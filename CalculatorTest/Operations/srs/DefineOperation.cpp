#include "Operations/headers/Operations.h"
#include "Operations/headers/DefineOperation.h"
#include <sstream>


void DefineOperation::makeOperation() {
    try{

        std::stringstream ss;
        ss << command_[2];

        double value = 0;

        ss >> value;

        if(ss.good()) {
            throw InvalidInput("Invalid value for define");
        }
        else
            context_.setArg(command_[1], std::stod(command_[2]));

    }
    catch (std::out_of_range & ex) {
        std::cout << "Value is out of the range of representable values" <<  ex.what();
        throw ex;
    }
    catch (InvalidInput & ex) {
        std::cout << "Invalid value for define";
        throw ex;
    }
}

DefineOperation::DefineOperation(Command &command, Context &context):Operations(context){
    command_ = command;
}