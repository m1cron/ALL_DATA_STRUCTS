#include <iostream>

#include "HashTable.cpp"

void write_file(const std::string& fileName, const std::string& str) {
    std::ofstream fs("../" + fileName, std::ios::in | std::ios::out | std::ios::binary | std::ios:: trunc);
    if (!fs)
        std::cout << "cannot open file\n";
    fs.write(str.c_str(), str.length());
    fs.close();
}

std::string read_file(const std::string& fileName) {
    std::ifstream is("../" + fileName, std::ios::out | std::ios::binary);
    if (!is)
        std::cout << "cannot open file\n";
    is.seekg(0, std::ios::end);
    int length = is.tellg();
    is.seekg(0, std::ios::beg);

    char *buf = new char[length];
    is.read(buf, length);
    is.close();
    return buf;
}

void num3(const std::string& key) {
    std::ifstream is("../1.bin", std::ios::out | std::ios::binary);
    if (!is)
        std::cout << "cannot open file\n";
    is.seekg(0, std::ios::end);
    int length = is.tellg();
    is.seekg(0, std::ios::beg);

    char *buf = new char[length];
    is.read(buf, length);
    is.close();

    for(char *i = strstr(buf , key.c_str()); i != nullptr && *i != '\n'; i++)
        std::cout << *i;
    std::cout << std::endl;
    delete[] buf;
}

void num4(const std::string& fileName, const std::string& key) {
    std::string buff = read_file(fileName);

    const char *start = strstr(buff.c_str(), key.c_str());
    if (start) {
        const char *end = strstr(start, "\n");
        if (end) {
            char *newbuff = (char*)malloc(buff.length() + 1);
            int startlen = (int) (start - buff.c_str());
            strncpy(newbuff, buff.c_str(), startlen);
            strcpy(newbuff+startlen,end+strlen("\n"));

            write_file(fileName, newbuff);

            free(newbuff);
        }
    }
    std::cout << "------------binary-file------------" << std::endl;
    std::cout << read_file(fileName) << std::endl;
    std::cout << "-----------------------------------" << std::endl;
}

void num8(const std::string& fileName) {
    auto *h = new HashTable<std::string, std::string>;
    h->insert("123",   "5785646461");
    h->insert("2",    "3456364534");
    h->insert("4",    "2346435364");
    h->insert("7",    "2345678901");
    h->deleteNode("7");
    std::string buff = h->get("123") + "\n" + h->get("2") + "\n" + h->get("4") + "\n" ;
    h->display();
    write_file(fileName, buff);
    std::cout << read_file(fileName);
}

void find(const std::string& fileName, const std::string& find) {
    std::ifstream file("../" + fileName);
    std::string str;
    while (std::getline(file, str)) {
        if (strstr(str.c_str(), find.c_str()) != nullptr)
            std::cout << str << std::endl;
    }
    file.close();
}

int main() {
    //std::string test = "1313 test\n123 loh\n6778 rewrwer\n4325 34587";
    //num1("1.bin", test);
    //std::cout << "------------binary-file------------" << std::endl;
    //std::cout << num2(1.bin) << std::endl;
    //std::cout << "-----------------------------------" << std::endl;
    //num3("1213");
    //num4("1.bin", "123");
    //num8("8.txt");
    //num6("6.txt", "cat");

    auto *h = new HashTable<std::string, std::string>;
    h->insert("а000фя",   "в угоне");
    h->insert("а228бв",    "нет");
    h->insert("а420уф",    "в угоне");
    h->insert("о000оо",    "нет");
    std::string buff = "а000фя " + h->get("а000фя") + "\nа228бв " + h->get("а228бв") + "\nа420уф " + h->get("а420уф") + "\nо000оо " + h->get("о000оо");
    write_file("test.txt", buff);
    std::cout << "out:\n" << read_file("test.txt") << "\n\nпоиск по номеру:\n";
    find("test.txt", "а000фя");
    std::cout << "\nпоиск по ключевому слову\n";
    find("test.txt", "в угоне");
    std::cout << "\n";
    find("test.txt", "нет");
    return 0;
}
