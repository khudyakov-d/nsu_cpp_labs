#include "Factories/headers/MulFactory.h"
#include "Operations/headers/MulOperation.h"

Operations * MulFactory::createOperation(Command &command, Context &context) {
    return new MulOperation(command , context);
}
