#include <stdexcept>

class ZeroDivision : public std::invalid_argument{
public:
    ZeroDivision(std::string msg);
};
