#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

void sortedInsert(Node *&head_ref, int data) {
    Node* newNode = new Node{data, nullptr, nullptr};

    if (head_ref == nullptr) {
        newNode->next = newNode;
        newNode->prev = newNode;
        head_ref = newNode;
        return;
    }

    if (data < head_ref->data) {
        Node* tail = head_ref->prev;

        newNode->next = head_ref;
        newNode->prev = tail;
        tail->next = newNode;
        head_ref->prev = newNode;
        head_ref = newNode;
        return;
    }

    Node* current = head_ref;
    while (current->next != head_ref && current->next->data < data) {
        current = current->next;
    }

    newNode->next = current->next;
    newNode->prev = current;
    current->next->prev = newNode;
    current->next = newNode;
}

void printList(Node *head_ref)
{
    if (head_ref == nullptr)
    {
        cout << "List kosong" << endl;
        return;
    }

    Node *current = head_ref;
    do
    {
        cout << current->data << " ";
        current = current->next;
    } while (current != head_ref);
    cout << endl;
}

int main()
{
    Node *head = nullptr;
    sortedInsert(head, 30);
    sortedInsert(head, 10);
    sortedInsert(head, 40);
    sortedInsert(head, 20);
    cout << "Circular Doubly Linked List (sorted): ";
    printList(head);

    return 0;
}

// Program ini dipakai buat nyisipin node baru ke dalam circular double linked list yang isinya selalu terurut naik (ascending)
// Kalau list masih kosong, node pertama bakal jadi head sekaligus nunjuk ke dirinya sendiri
// Kalau data yang masuk lebih kecil dari head, node itu langsung ditaruh di depan dan head diganti ke node baru
// Kalau datanya lebih besar, program bakal nyari posisi yang pas di tengah atau akhir list buat nyelipin node baru
// Hasil akhirnya list selalu rapi urut naik, misalnya kalau masukin 30, 10, 40, dan 20, urutannya jadi 10 20 30 40
