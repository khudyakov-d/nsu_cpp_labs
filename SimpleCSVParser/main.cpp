#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <list>
#include <iomanip>

//Заполняет map словами из inputFile
int fillWordsInMap(std::map<std::string,int> &dictionary, std::ifstream &inputFile)
{
    int k = 0, j = 0, i;
    std::string token, str;

    while (std::getline(inputFile, str)) {
        for (i = 0; i < str.length(); i++) {
            if (((str[i] != ' ') && (str[i] != '.') && (str[i] != ',') && (str[i] != '!') && (str[i] != '?'))) {
                token.push_back(str[i]);
                j++;
            }
            else if (j > 0) {
                k++;
                dictionary[token]++;
                j = 0;
                token.clear();
            }
        }

        if (j != 0) {
            dictionary[token]++;
            k++;
        }
    }

    return k;
}

int main(int argc, char** argv) {

    std::ifstream inputFile;
    std::ofstream outFile;
    std::list<int> values;
    std::list<int>::iterator it;
    std::map < std::string , int> dictionary;
    std::map < std::string , int>::iterator cur;
    int j = 0, i, k = 0;

    inputFile.open(argv[1]);
    outFile.open(argv[2]);

    if (!inputFile.is_open()){
        std::cout << "File can't be open!\n";
        return 1;
    }
    else
        k = fillWordsInMap(dictionary,inputFile);

    for (cur = dictionary.begin(); cur != dictionary.end(); cur++)
        values.push_back((*cur).second);

    values.sort();
    values.reverse();

    for (it = values.begin(); it != values.end(); it++)
        for (cur = dictionary.begin(); cur != dictionary.end(); cur++)
            if ((*it) == (*cur).second) {
                outFile << (*cur).first << "," << (*cur).second << ",";
                outFile << std::fixed << std::setprecision(2) << ((double)(*cur).second/(double)k)*100 << "%" << "\n";
                dictionary.erase(cur);
                break;
            }

    inputFile.close();
    outFile.close();

    return 0;
}
