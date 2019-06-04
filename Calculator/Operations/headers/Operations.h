#pragma once
#include <iostream>
#include <vector>
#include "Context/Context.h"
#include "Exceptions/InvalidInput.h"
#include "Exceptions/EmptyStack.h"
#include "Exceptions/ZeroDivision.h"

enum nCommands {PUSH, POP, PLUS, MINUS, MUL, DIVISION, SQRT, PRINT, DEFINE};
using Command = std::vector<std::string>;
using Mapping = std::map<std::string,nCommands>;

class Operations {
protected:
    Command command_;
    Context & context_;
public:
    Operations(Context & context);
    virtual void makeOperation() = 0;
    virtual ~Operations() = default;
    static Operations * createOperation(Command &command, Context &context, Mapping & mapping);
};

