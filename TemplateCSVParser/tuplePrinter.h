#ifndef CSVPARSER_ITERATETUPLE_H
#define CSVPARSER_ITERATETUPLE_H

#include <tuple>
#include <fstream>
#include <iostream>

template<typename Tuple, unsigned N, unsigned Size>
struct tuple_printer {

    static void print(std::ostream& out, const Tuple& tuple) {
        out << std::get<N>(tuple) << " ";
        tuple_printer<Tuple, N + 1, Size>::print(out, tuple);
    }
};

template<typename Tuple, unsigned N>
struct tuple_printer<Tuple, N, N> {

    static void print(std::ostream& out, const Tuple& tuple) {
        out << std::get<N>(tuple);
    }
};

template<typename Tuple, unsigned N>
struct tuple_printer<Tuple, N, 0> {

    static void print(std::ostream& out, const Tuple& tuple) {
    }
};

template<typename... Args>
auto & operator<<(std::ostream& out, const std::tuple<Args...>& arg) {
    tuple_printer<std::tuple<Args...>, 0, sizeof...(Args) - 1>::print(out, arg);
    return out;
}


#endif //CSVPARSER_ITERATETUPLE_H

