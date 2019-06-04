#include "Factories/headers/DivisionFactory.h"
#include "Operations/headers/DivisionOperation.h"

Operations * DivisionFactory::createOperation(Command &command, Context &context) {
    return new DivisionOperation(command , context);
}
