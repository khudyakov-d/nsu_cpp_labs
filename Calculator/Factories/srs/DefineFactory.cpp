#include "Factories/headers/DefineFactory.h"
#include "Operations/headers/DefineOperation.h"

Operations * DefineFactory::createOperation(Command &command, Context &context) {
    return new DefineOperation(command , context);
}
