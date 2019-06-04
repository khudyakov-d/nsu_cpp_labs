#include <iostream>
#include "Operations/headers/Operations.h"
#include "Calculator/Calculator.h"
#include <fstream>

Command takeNewCommand(std::string &str)
{
    Command command;
    int k = 0;
    int i;

    for (i = 0; i < str.length(); i++) {
        if (str[i] == ' ') {
            command.push_back(str.substr(i-k,k));
            k=0;
        }
        else {
            k++;
        }

    }

    if (k>0){
        command.push_back(str.substr(i-k,k));
    }
    return command;
}

int main(int argc, char** argv) {
    std::ifstream inputFile;
    std::istream * fp = &std::cin;
    std::string str;
    Command command;
    Calculator calc;

    if (argc == 2){
        inputFile.open(argv[1]);
        fp = &inputFile;

        if (!inputFile.is_open()) {
            std::cout << "File can't be open!\n";
            return 1;
        }
    }

    while (std::getline(*fp, str)) {
        command = takeNewCommand(str);
        calc.exec(command);
    }


    return  0;
}
