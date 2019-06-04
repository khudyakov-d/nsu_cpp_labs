#include "Factories/headers/MinusFactory.h"
#include "Operations/headers/MinusOperation.h"

Operations *MinusFactory::createOperation(Command &command, Context &context) {
    return new MinusOperation(command , context);
}
