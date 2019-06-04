#include "Operations/headers/Operations.h"
#include "Operations/headers/PlusOperation.h"
#include "Operations/headers/MinusOperation.h"
#include "Operations/headers/PopOperation.h"
#include "Operations/headers/PushOperation.h"
#include "Operations/headers/MulOperation.h"
#include "Operations/headers/DivisionOperation.h"
#include "Operations/headers/SqrtOperation.h"
#include "Operations/headers/PrintOperation.h"
#include "Operations/headers/DefineOperation.h"

Operations::Operations(Context & context):context_(context) {
}

Operations * Operations::createOperation(Command &command, Context &context, Mapping & mapping) {
    Operations * op = nullptr;

    try {
        switch (mapping.at(command[0])) {
            case PUSH:
                op = new PushOperation(command, context);
                break;
            case POP:
                op = new PopOperation(command, context);
                break;
            case PLUS:
                op = new PlusOperation(command, context);
                break;
            case MINUS:
                op = new MinusOperation(command, context);
                break;
            case MUL:
                op = new MulOperation(command, context);
                break;
            case DIVISION:
                op = new DivisionOperation(command, context);
                break;
            case SQRT:
                op = new SqrtOperation(command, context);
                break;
            case PRINT:
                op = new PrintOperation(command, context);
                break;
            case DEFINE:
                op = new DefineOperation(command, context);
                break;
            }
    }
    catch (const std::bad_alloc &ex) {
        std::cout << "Allocation failed: " << ex.what() << '\n';
        throw ex;
    }
    catch (const std::out_of_range &ex) {
        std::cout << "Command not found: " << ex.what() << '\n';
        throw ex;
    }

    return  op;
}
