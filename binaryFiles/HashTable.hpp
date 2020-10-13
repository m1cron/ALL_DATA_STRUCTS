#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include "HashNode.hpp"

template<typename K, typename V>
class HashTable {
private:
    HashNode<K, V> **arr;
    int size;
    int capacity;
    HashNode<K, V> *dummy;
public: 
    HashTable();
    ~HashTable();
    int getHash(int key);
    void insert(K key, V value);
    V deleteNode(int key);
    V get(int key);
    int sizeofMap();
    bool isEmpty();
    void display();
};

#endif