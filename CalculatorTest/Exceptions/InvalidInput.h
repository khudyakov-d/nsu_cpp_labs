#include <stdexcept>

class InvalidInput : public std::invalid_argument{
public:
    InvalidInput(std::string msg);
};
