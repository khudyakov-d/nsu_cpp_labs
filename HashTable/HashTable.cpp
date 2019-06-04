#include "HashTable.h"


HashTable::HashTable() {
    countOfLists = 8;
    lists =  HTVector(8);
    employedCells = 0;
}

HashTable::HashTable(size_t count) {
    countOfLists = count;
    lists =  HTVector(count);
    employedCells = 0;
}

HashTable::~HashTable() {
    clearLists(lists);
}

void HashTable::clearLists(HTVector &vec) {
    for (int i = 0; i < vec.size(); ++i) {
        delete( vec[i] );
    }
    vec.clear();
}

void HashTable::copyLists(const HTVector &vec){
    int i,j;
    try {
        for (i = 0; i < vec.size(); ++i) {
            if (vec[i] != nullptr) {
                auto *list = new HTList;
                for (auto it = (vec)[i]->begin(); it != (vec)[i]->end(); it++) {
                    list->push_back(std::make_pair(it->first, it->second));
                }
                lists[i] = list;
            }
        }
    }
    catch(const std::bad_alloc& e) {
        for (j = 0; j<i; j++)
            delete(lists[j]);

        std::cout << "Allocation failed: " << e.what() << '\n';
    }
}

void HashTable::copyLists(HTVector &sampler, const HTVector &vec, bool &status){
    int i,j;
    try {
        for (i = 0; i < vec.size(); ++i) {
            if (vec[i] != nullptr) {
                auto *list = new HTList;
                for (auto it = (vec)[i]->begin(); it != (vec)[i]->end(); it++) {
                    list->push_back(std::make_pair(it->first, it->second));
                }
                sampler[i] = list;
            }
        }
    }
    catch(const std::bad_alloc& e) {
        status = true;
        for (j = 0; j<i; j++)
            delete(sampler[j]);

        std::cout << "Allocation failed: " << e.what() << '\n';
    }
}

HashTable::HashTable(const HashTable &b) {
    countOfLists = b.countOfLists;
    employedCells = b.employedCells;
    lists = (HTVector(countOfLists));
    copyLists(b.lists);
}

HashTable::HashTable(HashTable &&b) noexcept {
    countOfLists = b.countOfLists;
    employedCells = b.employedCells;
    lists = std::move(b.lists);
    b.lists.clear();
    b.countOfLists = 0;
    b.employedCells = 0;
}

HashTable& HashTable::operator=(const HashTable &b) {
    if (*this != b) {
        HTVector vec;
        bool status = false;

        vec = HTVector(countOfLists);
        copyLists(vec,b.lists,status);

        if(!status)
        {
            clearLists(lists);
            countOfLists = b.countOfLists;
            employedCells = b.employedCells;
            lists = vec;
        }
    }
    return *this;
}

void HashTable::realloc(size_t count) {
    try {
        HTVector newlists(count);
        for (int i = 0; i < countOfLists; ++i) {
            if (lists[i] != nullptr) {
                for (auto it = lists[i]->begin(); it != lists[i]->end(); it++) {
                    if (newlists[calcHash((*it).first) % count] == nullptr){
                        newlists[calcHash((*it).first) % count] = new HTList;
                    }
                    newlists[calcHash((*it).first) % count]->push_back(std::make_pair( (*it).first , (*it).second) );
                }
            }
        }

        clearLists(lists);
        lists = newlists;
        countOfLists = count;
    }
    catch (const std::bad_alloc &e) {
        std::cout << "Allocation failed: " << e.what() << '\n';
    }
}

bool HashTable::insert(const Key &k, const Value &v) {
    unsigned hash = calcHash(k);
    size_t keyPos;

    if (contains(k)) return false;

    if (employedCells >= ((countOfLists * 3) / 4))
        realloc(countOfLists * 2);

    keyPos = hash % countOfLists;

    try {
        if (lists[keyPos] == nullptr) {
            lists[keyPos] = new HTList;
        }

        lists[keyPos]->push_back(std::make_pair(k, v));
        employedCells++;
    }
    catch (const std::bad_alloc &e) {
        std::cout << "Allocation failed: " << e.what() << '\n';
        return false;
    }

    return true;
}

bool HashTable::contains(const Key& k) const {
    size_t keyPos = calcHash(k) % countOfLists;

    if (lists[keyPos] == nullptr) {
        return false;
    }
    for (auto it = lists[keyPos]->begin(); it != lists[keyPos]->end(); it++) {
        if ((*it).first == k)
            return true;
    }
    return false;
}

bool HashTable::erase(const Key& k) {
    size_t keyPos = calcHash(k) % countOfLists;

    if (lists[keyPos] != nullptr) {
        for (auto it = lists[keyPos]->begin(); it != lists[keyPos]->end(); it++) {
            if ((*it).first == k) {
                employedCells--;
                lists[keyPos]->erase(it);
                return true;
            }
        }
    }

    return false;
}

Value& HashTable::operator[](const Key& k) {
    struct Value *defaultValue;
    size_t keyPos = calcHash(k) % countOfLists;

    if (lists[keyPos] != nullptr) {
        for (auto it = lists[keyPos]->begin(); it != lists[keyPos]->end(); it++) {
            if ((*it).first == k)
                return (*it).second;
        }
    }
    try {
        defaultValue = new Value();
        insert(k, *defaultValue);
        return *defaultValue;
    }
    catch (const std::bad_alloc &e) {
        std::cout << "Allocation failed: " << e.what() << '\n';
    }
}

Value& HashTable::findValue(const Key& k) const{
    size_t keyPos = calcHash(k) % countOfLists;

    try {
        if (lists[keyPos] != nullptr) {
            for (auto it = lists[keyPos]->begin(); it != lists[keyPos]->end(); it++) {

                if ((*it).first == k)
                    return (*it).second;
            }
        }
        throw "Out of range error";
    }
    catch (const char *e) {
        std::cout << e;
    }
}

Value& HashTable::at(const Key& k) {
    findValue(k);
}

const Value& HashTable::at(const Key& k) const {
    findValue(k);
}

size_t HashTable::size() const {
    return this->countOfLists;
}

bool HashTable::empty() const {
    return employedCells == 0;
}

void HashTable::swap(HashTable &b) {
    std::swap(countOfLists, b.countOfLists);
    std::swap(lists, b.lists);
    std::swap(employedCells, b.employedCells);;
}

void HashTable::clear() {
    countOfLists = 8;
    employedCells = 0;
    clearLists(lists);
    lists = HTVector(8);
}

bool operator!=(const struct Value a,const struct Value b) {
    return (a.weight != b.weight) || (a.age != b.age);
}

bool operator==(const HashTable & a, const HashTable & b) {

    if (a.countOfLists != b.countOfLists) {
        return false;
    }

    for (int i = 0; i < b.countOfLists; ++i) {

        if ((a.lists[i] != nullptr && b.lists[i] == nullptr) || (a.lists[i] == nullptr && b.lists[i] != nullptr)){
            return false;
        }

        if (a.lists[i] != nullptr && b.lists[i] != nullptr) {

            if (a.lists[i]->size() != b.lists[i]->size()) {
                return false;
            }

            auto ita = a.lists[i]->begin();
            for (auto it = b.lists[i]->begin(); it != b.lists[i]->end(); it++) {
                    if ((it->first != ita->first) || (it->second != ita->second))
                        return false;
                    ita++;
            }

        }
    }

    return true;
}

bool operator!=(const HashTable & a, const HashTable & b) {
    return !(a == b);
}

unsigned HashTable::calcHash(const Key &key) const {
    unsigned h = 37;

    for (auto s:key)
        h = (h * 54059) ^ (s * 76963);

    return h % 86969;
}
