#include "Factories/headers/SqrtFactory.h"

Operations * SqrtFactory::createOperation(Command &command, Context &context) {
    return new SqrtOperation(command , context);
}
