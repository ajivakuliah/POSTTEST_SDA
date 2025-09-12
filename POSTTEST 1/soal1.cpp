#include <iostream>
using namespace std;

void balik(int *arr, int n) {
    for (int *a = arr, *b = arr + n - 1; a < b; a++, b--)
        swap(*a, *b);
}

int main() {
    const int n = 7;

    int angka_ganjil[n];
    for (int i = 0; i < n; i++) angka_ganjil[i] = (i + 1) * 3;
    cout << "belum dibalik: ";
    for (int x : angka_ganjil) cout << x << " "; cout << endl;

    balik(angka_ganjil, n);
    cout << "Setelah dibaliik: ";
    for (int x : angka_ganjil) cout << x << " "; cout << endl;
}
