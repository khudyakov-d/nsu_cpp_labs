#ifndef CSVPARSER_CSVPARSER_H
#define CSVPARSER_CSVPARSER_H

#include "tuplePrinter.h"
#include "tupleFiller.h"
#include "CSVIterator.h"
#include <vector>
#include <sstream>


template<typename... Args>
class CSVParser {
public:
    CSVParser(std::ifstream *in, char ch = ',') : in_(in) {
        int k = 0;
        std::string str;
        std::vector<std::string> strVec;
        std::tuple<Args...> tuple;

        while (std::getline(*in_, str)) {
            strVec = divideString(str,ch);
            try {
                if (strVec.size() != sizeof...(Args))
                    throw std::invalid_argument("Invalid number of parameters per line\n");

                makeTuple<Args...>(tuple, strVec);
                tupleVec_.push_back(tuple);
            }
            catch (std::pair<std::invalid_argument, unsigned> &e) {
                std::cout << e.first.what() << " row: " << k << " column: " << e.second << std::endl;
            }
            catch (std::invalid_argument &e) {
                std::cout << e.what() << std::endl;
            }

            k++;
        }
    }


    std::vector<std::string> divideString(std::string &str, char ch) {
        std::vector<std::string> res;
        size_t k = 0, i;

        for (i = 0; i < str.length(); i++) {
            if (str[i] == ch) {
                res.push_back(str.substr(i - k, k));
                k = 0;
            } else {
                k++;
            }

        }

        if (k > 0) {
            res.push_back(str.substr(i - k, k));
        }
        return res;
    }

    CSVIterator<Args...> begin() const {
        return CSVIterator<Args...>(tupleVec_,0);
    }

    CSVIterator<Args...> end() const {
        return CSVIterator<Args...>(tupleVec_,tupleVec_.size());
    }


private:
    std::ifstream *in_;
    std::vector<std::tuple<Args...>> tupleVec_;
};

#endif //CSVPARSER_CSVPARSER_H
