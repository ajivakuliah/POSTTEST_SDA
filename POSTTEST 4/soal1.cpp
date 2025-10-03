#include <iostream>
#include <string>
using namespace std;

struct Node {
    char data;
    Node* next;
};

void push(Node*& top, char data) {
    Node* newNode = new Node{data, top};
    top = newNode;
}

char pop(Node*& top) {
    if (top == nullptr) return '\0';
    Node* temp = top;
    char poppedValue = temp->data;
    top = top->next;
    delete temp;
    return poppedValue;
}

string reverseString(string s) {
    Node* stackTop = nullptr;
    string reversed = "";

    for (char c : s) {
        push(stackTop, c);
    }

    while (stackTop != nullptr) {
        reversed += pop(stackTop);
    }

    return reversed;
}

int main() {
    string text = "Struktur Data";
    cout << "Teks asli: " << text << endl;
    cout << "Teks terbalik: " << reverseString(text) << endl;
    return 0;
}

// Secara singkat program ini berisikan penggunaan stack linked list yang dimana menggunakan fungsi/fitur push dan pop
// untuk memasukan tulisan "struktur data" dan di balik menjadi "atad rutkurts" (hal ini bisa terjadi karena sifat stack (LIFO)
