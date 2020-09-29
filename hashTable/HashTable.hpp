#ifndef HASH_HASHTABLE_HPP
#define HASH_HASHTABLE_HPP

#include <list>
#include <memory>

template<typename Key, typename Value>
class HashTable {
    unsigned long int   BUCKETS;                      // hash table size

    std::list<Value>    *table;
public:
    explicit            HashTable(unsigned long int size = 10);
    ~                   HashTable();
    void                insertItem(Key key, Value value);
    void                deleteItem(Key key);
    void                display();

    unsigned long int   hashFunc(Key key);
};

#endif //HASH_HASHTABLE_HPP
