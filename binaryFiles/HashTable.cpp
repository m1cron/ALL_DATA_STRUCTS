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
int HashTable<K, V>::getHash(int key) { return key % capacity; }

template<typename K, typename V>
void HashTable<K, V>::insert(K key, V value) {
    HashNode<K, V> *temp = new HashNode<K, V>(key, value);
    int hashIndex = getHash(key);
    while(arr[hashIndex] != NULL && arr[hashIndex]->key != key 
               && arr[hashIndex]->key != -1) { 
        hashIndex++; 
        hashIndex %= capacity; 
    } 
       
    if(arr[hashIndex] == NULL || arr[hashIndex]->key == -1) 
        size++; 
    arr[hashIndex] = temp;
}


template<typename K, typename V>
V HashTable<K, V>::deleteNode(int key) { 
    int hashIndex = getHash(key); 
          
    while(arr[hashIndex] != NULL) { 
        if(arr[hashIndex]->key == key) { 
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
V HashTable<K, V>::get(int key) { 
    int hashIndex = getHash(key); 
    int counter=0; 
    while(arr[hashIndex] != NULL) {    
        int counter =0; 
        if(counter++>capacity)
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
    for(int i=0 ; i<capacity ; i++) { 
        if(arr[i] != NULL && arr[i]->key != -1) 
            std::cout << "key = " << arr[i]->key  
                <<"  value = "<< arr[i]->value << std::endl; 
    } 
} 