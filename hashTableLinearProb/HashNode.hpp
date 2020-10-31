#ifndef HASH_NODE_H
#define HASH_NODE_H

#include <bits/stdc++.h>
template<typename K, typename V>
class HashNode {
public:
    K key;
    V value;
    size_t hash;
    HashNode(K key, V value, size_t hash);
};

#endif