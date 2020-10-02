#include <bits/stdc++.h>

#include "HashTable.cpp"

using namespace std;

int main(void) {
    auto *h = new HashTable<int, long>; 
    h->insert(10,   5785646461); 
    h->insert(2,    3456364534); 
    h->insert(4,    2346435364); 
    h->insert(7,    2345678901);
    h->display(); 
    std::cout << "map size -->> " << h->sizeofMap() << std::endl; 
    cout << "delete key 2 -->> " << h->deleteNode(2) << endl; 
    //cout << "map size -->> " << h->sizeofMap() <<endl; 
    //cout << "is empty map -->> " << h->isEmpty() << endl; 
    cout << "get elem -->> " << h->get(2) << endl; 
    return 0;
}