#include <string>
#include <vector>
#include <list>
#include <map>
#include <iostream>

struct Value {
    unsigned age;
    unsigned weight;
};

using Key = std::string;
using HTPair = std::pair< Key, Value >;
using HTList = std::list< HTPair >;
using HTVector = std::vector< HTList *>;

class HashTable {
public:
    HTVector lists;
    size_t countOfLists;
    size_t employedCells;
    HashTable();
    HashTable(size_t count);
    ~HashTable();
    HashTable(const HashTable& b);
    HashTable(HashTable &&b) noexcept;
    HashTable& operator=(const HashTable& b);
    bool insert(const Key& k, const Value& v);
    bool contains(const Key& k) const;
    bool erase(const Key& k);
    Value& operator[](const Key& k);
    Value& at(const Key& k);
    const Value& at(const Key& k) const;
    size_t size() const;
    bool empty() const;
    void swap(HashTable& b);
    void clear();
    friend bool operator==(const HashTable & a, const HashTable & b);
    friend bool operator!=(const HashTable & a, const HashTable & b);
private:
    void clearLists(HTVector &vec);
    void copyLists(const HTVector &vec);
    void copyLists(HTVector &sampler, const HTVector &vec, bool &status);
    unsigned calcHash(const Key &key) const;
    Value& findValue(const Key& k) const;
    void realloc(size_t count);
};

