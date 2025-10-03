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

bool areBracketsBalanced(string expr) {
    Node* stackTop = nullptr;

    for (char c : expr) {
        if (c == '(' || c == '{' || c == '[') {
            push(stackTop, c);
        }
        else if (c == ')' || c == '}' || c == ']') {
            if (stackTop == nullptr) return false;

            char topChar = pop(stackTop);

            if ((c == ')' && topChar != '(') ||
                (c == '}' && topChar != '{') ||
                (c == ']' && topChar != '[')) {
                return false;
            }
        }
    }

    return (stackTop == nullptr);
}

int main() {
    string expr1 = "{[()]}";
    cout << expr1 << " -> " << (areBracketsBalanced(expr1) ? "Seimbang" : "Tidak Seimbang") << endl;
    string expr2 = "{[(])}";
    cout << expr2 << " -> " << (areBracketsBalanced(expr2) ? "Seimbang" : "Tidak Seimbang") << endl;

    return 0;
}

// secara dasarnya program ini memanfaatkan stack untuk ngecek apakah tanda kurung di dalam sebuah teks string itu seimbang atau nggak 
// Jadi setiap kali ketemu kurung buka (, {, atau [, (kurung biasa, kurawal, maupun kotak) dia bakal dimasukin ke stack
// Pas nemu kurung tutup ), }, atau ], stack akan di-pop untuk ngecek apakah pasangannya cocok
// Kalau ada kurung tutup yang nggak punya pasangan, atau urutannya salah, hasilnya langsung "Tidak Seimbang"
// Contohnya, "{[()]}" dianggap seimbang, tapi "{[(])}" bakal ketahuan nggak seimbang
