#include "HashTable.cpp"

using namespace std;

int main(void) {
    auto *h = new HashTable<unsigned long long int, std::string>;
    h->insert(10,   "dgfhkjhdgfhlkjdgfhlkjdgfhlkjdgfhlkjdgfhlkjdgflkjhdgflkjhdgflkjhdgflkjhdgfslkjh");
    h->insert(2,    "34659879346587987346590873465908734659087egfhijhdlgfkjdgfhkjdgfkjoh");
    h->insert(4,    "34659087346598746598793465879346587946508790873465");
    h->insert(7,    "234534659087346598734659087346590873465908734656");
    h->display(); 
    std::cout << "map size -->> " << h->sizeofMap() << std::endl; 
    cout << "delete key 2 -->> " << h->deleteNode(2) << endl;
    h->display();
    //cout << "map size -->> " << h->sizeofMap() <<endl; 
    //cout << "is empty map -->> " << h->isEmpty() << endl; 
    //cout << "get elem -->> " << h->get(2) << endl;
    return 0;
}