#include "Factories/headers/PopFactory.h"

Operations * PopFactory::createOperation(Command &command, Context &context) {
    return new PopOperation(command , context);
}
