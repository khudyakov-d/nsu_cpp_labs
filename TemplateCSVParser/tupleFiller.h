#ifndef CSVPARSER_TUPLEFILLER_H
#define CSVPARSER_TUPLEFILLER_H

#include <tuple>
#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>

template<typename Tuple, unsigned N, unsigned Size>
struct fillTuple {

    static void fill(Tuple &tuple, const std::vector<std::string> &vector) {
        std::stringstream ss;

        ss << vector[N];
        ss >> std::get<N>(tuple);

        if (ss.fail()) {
            throw std::make_pair(std::invalid_argument("Type mismatch"), N);
        }

        try {
            fillTuple<Tuple, N + 1, Size>::fill(tuple, vector);
        }
        catch (std::pair<std::invalid_argument, int> &e) {
            throw e;
        }
    }
};

template<typename Tuple, unsigned N>
struct fillTuple<Tuple, N, N> {

    static void fill(Tuple &tuple, const std::vector<std::string> &vector) {

        std::stringstream ss;
        ss << vector[N];
        ss >> std::get<N>(tuple);

        if (ss.fail()) {
            throw std::make_pair(std::invalid_argument("Type mismatch"), N);
        }

    }
};

template<typename Tuple, unsigned N>
struct fillTuple<Tuple, N, 0> {

    static void fill(Tuple &tuple, const std::vector<std::string> &vector) {
    }
};

template<typename... Args>
void makeTuple(std::tuple<Args...> &arg, std::vector<std::string> strVec) {
    try {
        fillTuple<std::tuple<Args...>, 0, sizeof...(Args) - 1>::fill(arg, strVec);
    }
    catch (std::pair<std::invalid_argument, unsigned> &e) {
        throw e;
    }
}

#endif //CSVPARSER_TUPLEFILLER_H
