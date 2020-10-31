#include <bits/stdc++.h>

#include "HashNode.hpp"
#include "HashNode.cpp"
#include "HashTable.hpp"

template<typename K, typename V>
HashTable<K, V>::HashTable() {
    capacity = 20;
    size = 0;
    arr = new HashNode<K, V>*[capacity];
    for(int i = 0; i < capacity; i++)
        arr[i] = NULL;
}

template<typename K, typename V>
HashTable<K, V>::~HashTable() { delete[] arr; }
    
template<typename K, typename V>
int HashTable<K, V>::getHash(size_t key) { return key % capacity; }

template<typename K, typename V>
void HashTable<K, V>::insert(K key, V value) {
    auto *temp = new HashNode<K, V>(key, value, std::hash<K>{}(key));
    int hashIndex = getHash(temp->hash);
    while(arr[hashIndex] != NULL && arr[hashIndex]->key != key )
    {
        hashIndex++; 
        hashIndex %= capacity; 
    } 
       
    if(arr[hashIndex] == NULL )
        size++; 
    arr[hashIndex] = temp;
}

template<typename K, typename V>
V HashTable<K, V>::deleteNode(K key) {
    size_t hash = std::hash<K>{}(key);
    int hashIndex = getHash(hash);
          
    while(arr[hashIndex] != NULL) { 
        if(arr[hashIndex]->hash == hash) {
            HashNode<K,V> *temp = arr[hashIndex];
            arr[hashIndex] = dummy;                   
            size--; 
            return temp->value; 
        } 
        hashIndex++; 
        hashIndex %= capacity;
    } 
    return (K)NULL; 
}

template<typename K, typename V>
V HashTable<K, V>::get(K key) {
    int hashIndex = getHash(std::hash<K>{}(key));
    int counter = 0;
    while(arr[hashIndex] != NULL) {
        if(counter++ > capacity)
            return (K)NULL;         
        if(arr[hashIndex]->key == key) 
            return arr[hashIndex]->value; 
        hashIndex++; 
        hashIndex %= capacity; 
    }
    return (K)NULL; 
}

template<typename K, typename V>
int HashTable<K, V>::sizeofMap() { return size; } 
      
template<typename K, typename V>
bool HashTable<K, V>::isEmpty() { return size == 0; } 

template<typename K, typename V>
void HashTable<K, V>::display() { 
    for(int i = 0; i < capacity; i++) {
        if(arr[i] != NULL)
            std::cout << "key = " << arr[i]->key << " hash = " << arr[i]->hash << "  value = "<< arr[i]->value << std::endl;
    } 
} 