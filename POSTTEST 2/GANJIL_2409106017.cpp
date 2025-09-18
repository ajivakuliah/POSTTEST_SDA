#include <iostream>
#include <string>
using namespace std;


struct Node {
    string namaItem;
    int jumlah;
    string tipe;
    Node* next;
};

Node* head = NULL;

const int JUMLAH_AWAL = 17;
const int POSISI_SISIP = 8;

Node* buatNode(string nama, string tipe) {
    Node* baru = new Node;
    baru->namaItem = nama;
    baru->tipe = tipe;
    baru->jumlah = JUMLAH_AWAL;
    baru->next = NULL;
    return baru;
}

void tambahItem(string nama, string tipe) {
    Node* baru = buatNode(nama, tipe);
    if (head == NULL) {
        head = baru;
    } else {
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = baru;
    }
    cout << "Item \"" << nama << "\" berhasil ditambahkan dengan jumlah " << JUMLAH_AWAL << endl;
}

void sisipItem(string nama, string tipe) {
    Node* baru = buatNode(nama, tipe);

    if (head == NULL) {
        head = baru;
        return;
    }

    if (POSISI_SISIP == 1) {
        baru->next = head;
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
    temp->next = baru;

    cout << "Item \"" << nama << "\" berhasil disisipkan di posisi " << count + 1 << endl;
}

void hapusItemTerakhir() {
    if (head == NULL) {
        cout << "Inventory kosong!" << endl;
        return;
    }
    if (head->next == NULL) {
        cout << "Item \"" << head->namaItem << "\" dihapus." << endl;
        delete head;
        head = NULL;
        return;
    }

    Node* temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    cout << "Item \"" << temp->next->namaItem << "\" dihapus." << endl;
    delete temp->next;
    temp->next = NULL;
}

void gunakanItem(string nama) {
    if (head == NULL) {
        cout << "Inventory kosong!" << endl;
        return;
    }

    Node* temp = head;
    Node* prev = NULL;

    while (temp != NULL && temp->namaItem != nama) {
        prev = temp;
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
        if (prev == NULL) {
            head = temp->next;
        } else {
            prev->next = temp->next;
        }
        delete temp;
    }
}

void tampilkanInventory() {
    if (head == NULL) {
        cout << "Inventory kosong!" << endl;
        return;
    }

    cout << "\n===== INVENTORY SAAT INI =====" << endl;
    Node* temp = head;
    int idx = 1;
    while (temp != NULL) {
        cout << idx++ << ". " << temp->namaItem 
             << " | Jumlah: " << temp->jumlah 
             << " | Tipe: " << temp->tipe << endl;
        temp = temp->next;
    }
    cout << "==============================" << endl;
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
        cout << "|                   GAME INVENTORY MANAGEMENT                  |" << endl;
        cout << "|              [ " << nama << " - " << nim << " ]" << endl;
        cout << "+--------------------------------------------------------------+" << endl;
        cout << "| 1. Add new item                                              |" << endl;
        cout << "| 2. Slip/insert Item                                          |" << endl;
        cout << "| 3. delete last item                                          |" << endl;
        cout << "| 4. use Item                                                  |" << endl;
        cout << "| 5. show Inventory                                            |" << endl;
        cout << "| 0. exit                                                    |" << endl;
        cout << "+--------------------------------------------------------------+" << endl;
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
            case 0:
                cout << "Keluar dari program..." << endl;
                break;
            default:
                cout << "Pilihan tidak valid!" << endl;
        }

    } while (pilihan != 0);

    return 0;
}
