#include "Context.h"
#include "Exceptions/EmptyStack.h"

Context::Context()
{
    table_ = std::map<std::string, double>();
    stack_  = std::stack<double>();
}

void Context::push(double value) {
    stack_.push(value);
}

double Context::pop() {
    if (stack_.size() > 0){
        double value = stack_.top();
        stack_.pop();
        return  value;
    }
    else throw EmptyStack("Stack is empty");

}

double Context::top() {
    if (stack_.size() > 0) {
        return stack_.top();
    }
    else throw EmptyStack("Stack is empty");

}

void Context::setArg(std::string & argName, double argValue) {
    table_[argName] = argValue;
}

bool Context::containsArg(std::string & argName)
{
    return (table_.count(argName) > 0);
}

double Context::topArg(std::string & argName)
{
    try {
        return table_.at(argName);
    }
    catch(const std::out_of_range & ex) {
        std::cout << ex.what();
    }
}
