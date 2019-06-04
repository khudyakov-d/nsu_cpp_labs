#ifndef CSVPARSER_CSVITERATOR_H
#define CSVPARSER_CSVITERATOR_H

#include <tuple>
#include <fstream>
#include <iostream>
#include <vector>
#include "tupleFiller.h"

template<typename... Args>
class CSVIterator {
public:
    CSVIterator(const std::vector<std::tuple<Args...>> & tupleVec, size_t index) : tupleVec_(tupleVec) {
        index_  = index;
    }

    CSVIterator & operator++() {
        index_++;
        return *this;
    }

    const std::tuple<Args...> operator*() const {
        return tupleVec_[index_];
    }

    friend bool operator== (const CSVIterator & lit, const CSVIterator & rit)
    {
        return (&lit.tupleVec_ == &rit.tupleVec_) && (lit.index_ == rit.index_);
    }

    friend bool operator!=(const CSVIterator &lit, const CSVIterator &rit) {
        return !(lit == rit);
    }


private:
    const std::vector<std::tuple<Args...>> & tupleVec_;
    size_t index_;
};


#endif //CSVPARSER_CSVITERATOR_H
