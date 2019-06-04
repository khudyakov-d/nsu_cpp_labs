#include <stdexcept>

class EmptyStack : public std::invalid_argument{
public:
    EmptyStack(std::string msg);
};
