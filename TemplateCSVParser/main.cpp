#include <iostream>
#include "tuplePrinter.h"
#include "CSVParser.h"


int main() {

    std::ifstream inputFile("text.csv");

    if (!inputFile.is_open()) {
        std::cout << "File can't be open!\n";
        return 1;
    }

    CSVParser<int, std::string> parser(&inputFile);
    for (std::tuple<int, std::string> rs : parser) {
        std::cout << rs << std::endl;
    }

    return 0;
}
