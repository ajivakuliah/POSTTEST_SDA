#include <iostream>
#include <string>
using namespace std;

struct Node {
    string document;
    Node* next;
};

void enqueue(Node*& front, Node*& rear, string document) {
    Node* newNode = new Node{document, nullptr};

    if (front == nullptr) {
        front = newNode;
        rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
}

string dequeue(Node*& front, Node*& rear) {
    if (front == nullptr) return "";

    Node* temp = front;
    string doc = temp->document;

    front = front->next;

    if (front == nullptr) {
        rear = nullptr;
    }

    delete temp;
    return doc;
}

void processAllDocuments(Node*& front, Node*& rear) {
    while (front != nullptr) {
        string doc = dequeue(front, rear);
        cout << "Memproses: " << doc << endl;
    }
}

int main() {
    Node* front = nullptr;
    Node* rear = nullptr;

    enqueue(front, rear, "Document1.pdf");
    enqueue(front, rear, "Report.docx");
    enqueue(front, rear, "Presentation.pptx");

    cout << "Memulai pemrosesan antrian printer:" << endl;
    processAllDocuments(front, rear);

    return 0;
}

// Program ini bikin simulasi antrian printer pakai linked list dengan prinsip FIFO (First In, First Out)
// Jadi kalau ada dokumen baru masuk, dia dimasukin ke belakang antrian lewat fungsi enqueue
// Sebaliknya, fungsi dequeue bakal ngambil dokumen dari depan antrian buat diproses
// Ada juga fungsi processAllDocuments yang bakal ngejalanin dequeue berulang-ulang sampai semua dokumen habis
// Intinya, dokumen yang lebih dulu masuk bakal lebih dulu diproses, contohnya Document1.pdf, Report.docx, dam Presentation.pptx
