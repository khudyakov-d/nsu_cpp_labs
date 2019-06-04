#include "Factories/headers/PlusFactory.h"

Operations * PlusFactory::createOperation(Command &command, Context &context) {
    return new PlusOperation(command , context);
}
