#include <iostream>
#include "HashTable.h"

int main()
{
    HashTable table;
    HashTable table1 = HashTable(20);

    table = table1;
    return 0;
}
