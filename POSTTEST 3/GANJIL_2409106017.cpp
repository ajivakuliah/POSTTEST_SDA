#include <iostream>
#include <string>
using namespace std;

struct Node {
    int id;
    string namaItem;
    int jumlah;
    string tipe;
    Node* next;
    Node* prev;
};

Node* head = NULL;
Node* tail = NULL;
int idCounter = 1;

const int JUMLAH_AWAL = 17;
const int POSISI_SISIP = 8;

Node* buatNode(string nama, string tipe) {
    Node* baru = new Node;
    baru->id = idCounter++;
    baru->namaItem = nama;
    baru->tipe = tipe;
    baru->jumlah = JUMLAH_AWAL;
    baru->next = NULL;
    baru->prev = NULL;
    return baru;
}

void tambahItem(string nama, string tipe) {
    Node* baru = buatNode(nama, tipe);
    if (head == NULL) {
        head = tail = baru;
    } else {
        tail->next = baru;
        baru->prev = tail;
        tail = baru;
    }
    cout << "Item \"" << nama << "\" berhasil ditambahkan dengan jumlah " << JUMLAH_AWAL << endl;
}

void sisipItem(string nama, string tipe) {
    Node* baru = buatNode(nama, tipe);

    if (head == NULL) {
        head = tail = baru;
        return;
    }

    if (POSISI_SISIP == 1) {
        baru->next = head;
        head->prev = baru;
        head = baru;
        return;
    }

    Node* temp = head;
    int count = 1;
    while (temp->next != NULL && count < POSISI_SISIP - 1) {
        temp = temp->next;
        count++;
    }

    baru->next = temp->next;
    if (temp->next != NULL) {
        temp->next->prev = baru;
    } else {
        tail = baru; // update tail jika disisip di akhir
    }
    temp->next = baru;
    baru->prev = temp;

    cout << "Item \"" << nama << "\" berhasil disisipkan di posisi " << count + 1 << endl;
}

void hapusItemTerakhir() {
    if (head == NULL) {
        cout << "Inventory kosong!" << endl;
        return;
    }
    if (head == tail) {
        cout << "Item \"" << head->namaItem << "\" dihapus." << endl;
        delete head;
        head = tail = NULL;
        return;
    }

    cout << "Item \"" << tail->namaItem << "\" dihapus." << endl;
    Node* hapus = tail;
    tail = tail->prev;
    tail->next = NULL;
    delete hapus;
}

void gunakanItem(string nama) {
    if (head == NULL) {
        cout << "Inventory kosong!" << endl;
        return;
    }

    Node* temp = head;

    while (temp != NULL && temp->namaItem != nama) {
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Item \"" << nama << "\" tidak ditemukan!" << endl;
        return;
    }

    temp->jumlah--;
    cout << "Item \"" << nama << "\" digunakan. Sisa jumlah: " << temp->jumlah << endl;

    if (temp->jumlah == 0) {
        cout << "Jumlah 0, item \"" << nama << "\" dihapus dari inventory." << endl;

        if (temp == head && temp == tail) {
            head = tail = NULL;
        } else if (temp == head) {
            head = head->next;
            head->prev = NULL;
        } else if (temp == tail) {
            tail = tail->prev;
            tail->next = NULL;
        } else {
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
        }
        delete temp;
    }
}

void tampilkanInventory() {
    if (head == NULL) {
        cout << "Inventory kosong!" << endl;
        return;
    }

    cout << "\n===== INVENTORY (DARI DEPAN) =====" << endl;
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->id << ". " << temp->namaItem 
             << " | Jumlah: " << temp->jumlah 
             << " | Tipe: " << temp->tipe << endl;
        temp = temp->next;
    }
    cout << "=================================" << endl;
}

void tampilkanInventoryBelakang() {
    if (tail == NULL) {
        cout << "Inventory kosong!" << endl;
        return;
    }

    cout << "\n===== INVENTORY (DARI BELAKANG) =====" << endl;
    Node* temp = tail;
    while (temp != NULL) {
        cout << temp->id << ". " << temp->namaItem 
             << " | Jumlah: " << temp->jumlah 
             << " | Tipe: " << temp->tipe << endl;
        temp = temp->prev;
    }
    cout << "====================================" << endl;
}

void detailItem() {
    if (head == NULL) {
        cout << "Inventory kosong!" << endl;
        return;
    }

    cout << "Cari item berdasarkan (1) ID atau (2) Nama? ";
    int pilihan; cin >> pilihan;
    cin.ignore();

    if (pilihan == 1) {
        int id;
        cout << "Masukkan ID item: ";
        cin >> id;
        Node* temp = head;
        while (temp != NULL && temp->id != id) {
            temp = temp->next;
        }
        if (temp == NULL) {
            cout << "Item dengan ID " << id << " tidak ditemukan!" << endl;
        } else {
            cout << "\n=== DETAIL ITEM ===" << endl;
            cout << "ID     : " << temp->id << endl;
            cout << "Nama   : " << temp->namaItem << endl;
            cout << "Jumlah : " << temp->jumlah << endl;
            cout << "Tipe   : " << temp->tipe << endl;
        }
    } else if (pilihan == 2) {
        string namaCari;
        cout << "Masukkan nama item: ";
        getline(cin, namaCari);
        Node* temp = head;
        while (temp != NULL && temp->namaItem != namaCari) {
            temp = temp->next;
        }
        if (temp == NULL) {
            cout << "Item dengan nama \"" << namaCari << "\" tidak ditemukan!" << endl;
        } else {
            cout << "\n=== DETAIL ITEM ===" << endl;
            cout << "ID     : " << temp->id << endl;
            cout << "Nama   : " << temp->namaItem << endl;
            cout << "Jumlah : " << temp->jumlah << endl;
            cout << "Tipe   : " << temp->tipe << endl;
        }
    } else {
        cout << "Pilihan tidak valid!" << endl;
    }
}

int main() {
    string nama, nim;
    cout << "Masukkan Nama: ";
    getline(cin, nama);
    cout << "Masukkan NIM: ";
    cin >> nim;

    int pilihan;
    do {
        cout << "\n+------------------------------------------------------------+" << endl;
        cout << "|                   GAME INVENTORY MANAGEMENT                |" << endl;
        cout << "|              [ " << nama << " - " << nim << " ]" << endl;
        cout << "+------------------------------------------------------------+" << endl;
        cout << "| 1. Add new item                                            |" << endl;
        cout << "| 2. Slip/insert Item                                        |" << endl;
        cout << "| 3. Delete last item                                        |" << endl;
        cout << "| 4. Use Item                                                |" << endl;
        cout << "| 5. Show Inventory (dari depan)                             |" << endl;
        cout << "| 6. Show Inventory (dari belakang)                          |" << endl;
        cout << "| 7. Detail Item (by ID/Nama)                                |" << endl;
        cout << "| 0. Exit                                                    |" << endl;
        cout << "+------------------------------------------------------------+" << endl;
        cout << "Pilih menu: ";
        cin >> pilihan;
        cin.ignore();

        string namaItem, tipeItem;

        switch (pilihan) {
            case 1:
                cout << "Masukkan nama item: ";
                getline(cin, namaItem);
                cout << "Masukkan tipe item: ";
                getline(cin, tipeItem);
                tambahItem(namaItem, tipeItem);
                break;
            case 2:
                cout << "Masukkan nama item: ";
                getline(cin, namaItem);
                cout << "Masukkan tipe item: ";
                getline(cin, tipeItem);
                sisipItem(namaItem, tipeItem);
                break;
            case 3:
                hapusItemTerakhir();
                break;
            case 4:
                cout << "Masukkan nama item yang ingin digunakan: ";
                getline(cin, namaItem);
                gunakanItem(namaItem);
                break;
            case 5:
                tampilkanInventory();
                break;
            case 6:
                tampilkanInventoryBelakang();
                break;
            case 7:
                detailItem();
                break;
            case 0:
                cout << "Keluar dari program..." << endl;
                break;
            default:
                cout << "Pilihan tidak valid!" << endl;
        }

    } while (pilihan != 0);

    return 0;
}
