#include <iostream>
#include <cstring>

#include "HashTable.hpp"

template<typename Key, typename Value>
HashTable<Key, Value>::HashTable(unsigned long int size) {
    this->BUCKETS = size;
    table = new std::list<Value>[BUCKETS];
}

template<typename Key, typename Value>
HashTable<Key, Value>::~HashTable() {
    delete [] table;
}

template<typename Key, typename Value>
void HashTable<Key, Value>::insertItem(Key key, Value value) {
    unsigned long int index = hashFunc(key);
    table[index].push_back(value);
}

template<typename Key, typename Value>
void HashTable<Key, Value>::deleteItem(Key key) {
    unsigned long int index = hashFunc(key);
    std::string tmp;

    for(it = table[index].begin(); it != table[index].end(); it++) {
        tmp = *it;
        if (strcmp(tmp.c_str(), key.c_str()))
            break;
    }

    if (it != table[index].end())
        table[index].erase(it);
}

template<typename Key, typename Value>
bool HashTable<Key, Value>::search(Key key) {
    unsigned long int index = hashFunc(key);
    std::string tmp;

    for(it = table[index].begin(); it != table[index].end(); it++) {
        tmp = *it;
        if (strcmp(tmp.c_str(), key.c_str()))
            return (true);
    }

    if (it != table[index].end())
        return (true);
    return (false);
}

template<typename Key, typename Value>
void HashTable<Key, Value>::display() {
    for (int i = 0; i < BUCKETS; i++) {
        std::cout << i;
        for (auto x : table[i])
            std::cout << " --> " << x;
        std::cout << std::endl;
    }
}

template<typename Key, typename Value>
unsigned long int HashTable<Key, Value>::hashFunc(Key key) {
    std::hash<Key> hash;                                        //    <----- from std::
    return (hash(key) % BUCKETS);
}