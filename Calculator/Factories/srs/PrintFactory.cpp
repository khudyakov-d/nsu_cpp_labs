#include "Factories/headers/PrintFactory.h"

Operations * PrintFactory::createOperation(Command &command, Context &context) {
    return new PrintOperation(command , context);
}
