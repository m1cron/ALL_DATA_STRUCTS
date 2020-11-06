#include <bits/stdc++.h>
using namespace std;

vector<string> result_arr;

typedef struct MinHeapNode {
    string data;
    unsigned freq;
    MinHeapNode *left, *right;

    MinHeapNode(string data, unsigned freq) {
        left = right = nullptr;
        this->data = move(data);
        this->freq = freq;
    }
}               MinHeapNode;

typedef struct compare {
    bool operator()(MinHeapNode* l, MinHeapNode* r) {
        return (l->freq > r->freq);
    }
}               compare;

void printCodes(MinHeapNode* root, const string& str) {
    if (!root)
        return;
    if (root->data != "$") {
        cout << root->data << ": " << str << "\n";
        result_arr.push_back(str);
    }
    printCodes(root->left, str + "0");
    printCodes(root->right, str + "1");
}

void HuffmanCodes(string data[], int freq[], int size) {
    MinHeapNode *left, *right, *top;

    priority_queue<MinHeapNode*, vector<MinHeapNode*>, compare> minHeap;

    for (int i = 0; i < size; ++i)
        minHeap.push(new MinHeapNode(data[i], freq[i]));

    while (minHeap.size() != 1) {
        left = minHeap.top();
        minHeap.pop();

        right = minHeap.top();
        minHeap.pop();

        top = new MinHeapNode("$", left->freq + right->freq);
        top->left = left;
        top->right = right;
        minHeap.push(top);
    }
    printCodes(minHeap.top(), "");
}

void init_str() {   // не будет работать с кириллицей
    string str = "василий пупкин";
    cout << str << "\t" << "\n\n";

    int *count = new int[14];
    for (int i = 0; i < 14; i++) {
        count[i] = 1;
        for (int j = i + 1; j < 14; j++) {
            if (str[i] == str[j])
                count[i]++;
        }
        cout << str[i] << count[i] << endl;
    }
}

int main() {
    string arr[] = { "п", "у", "к", "и", "н", " ", "в", "а", "с", "л", "й", "р", "о", "ч" };
    int freq[] = { 8, 4, 8, 24, 4, 8, 8, 4, 4, 12, 4, 4, 4, 4 }; // в %
    HuffmanCodes(arr, freq, 14);
    for (auto &i : result_arr)
        cout << i << " ";
    //init_str();
    return 0;
}