#include "HashTable.cpp"


int main(int argc, char **argv) {
    auto *table0 = new HashTable<std::string, std::string>(2);
    table0->insertItem("123", "code");
    table0->insertItem("123", "code_collusion");
    table0->display();
    delete table0;

    std::cout << "\n\n";

    auto *table1 = new HashTable<std::string, std::string>(5);
    table1->insertItem("46572356423465726587123465734126587346587", "ОАО Далбоеб");
    table1->insertItem("98734579867394856734576983457698458769345", "ОАО Пидарас");
    table1->insertItem("94650879089083465908746598746590879465874", "ОАО Хуесос");
    table1->display();
    delete table1;

    return 0;
}