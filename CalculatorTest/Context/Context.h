#pragma once
#include <map>
#include <stack>
#include <iostream>

class Context {
public:
    void push(double value);
    double pop();
    double top();
    void setArg(std::string & argName, double argValue);
    bool containsArg(std::string & argName);
    double topArg(std::string &argName);
    Context();

private:
    std::map<std::string, double> table_;
    std::stack<double> stack_;
};

