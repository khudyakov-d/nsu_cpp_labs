#include "Factories/headers/PushFactory.h"

Operations * PushFactory::createOperation(Command &command, Context &context) {
    return new PushOperation(command , context);
}
