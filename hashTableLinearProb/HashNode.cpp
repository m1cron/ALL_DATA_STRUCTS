#include "HashNode.hpp"

template<typename K, typename V>
HashNode<K, V>::HashNode(K key, V value){
    this->key = key;
    this->value = value;
}