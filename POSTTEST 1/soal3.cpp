#include <iostream>
using namespace std;

struct Mahasiswa {
    string nama;
    string nim;
    double ipk;
};

int main() {
    const int N = 5;
    Mahasiswa mhs[N];

    for (int i = 0; i < N; i++) {
        cout << "Mahasiswa ke-" << i + 1 << endl;
        cout << "Nama : "; getline(cin >> ws, mhs[i].nama);
        cout << "NIM  : "; cin >> mhs[i].nim;
        cout << "IPK  : "; cin >> mhs[i].ipk;
        cout << endl;
    }

    int tertinggi = 0;
    for (int i = 1; i < N; i++) {
        if (mhs[i].ipk > mhs[tertinggi].ipk) {
            tertinggi = i;
        }
    }

    cout << "\nMahasiswa dengan IPK Tertinggi\n";
    cout << "Nama : " << mhs[tertinggi].nama << endl;
    cout << "NIM  : " << mhs[tertinggi].nim << endl;
    cout << "IPK  : " << mhs[tertinggi].ipk << endl;

    return 0;
}
