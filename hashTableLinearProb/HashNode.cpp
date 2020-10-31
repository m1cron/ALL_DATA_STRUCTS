#include "HashNode.hpp"

template<typename K, typename V>
HashNode<K, V>::HashNode(K key, V value, size_t hash){
    this->key = key;
    this->value = value;
    this->hash = hash;
}