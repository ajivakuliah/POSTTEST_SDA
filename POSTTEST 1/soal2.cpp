#include <iostream>
using namespace std;

int main() {
    int m[3][3] = { {3, 6, 9},
                    {12, 15, 18},
                    {21, 24, 27} };

    int utama = 0, sekunder = 0;

    for (int i = 0; i < 3; i++) {
        utama += m[i][i];
        sekunder += m[i][2 - i];
    }

    cout << "Matriks 3x3:\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << m[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Jumlah diagonal utama = " << utama; 
    cout << "Jumlah diagonal sekunder = " << sekunder;
    cout << "Total keduanya = " << (utama + sekunder) << endl;

    return 0;
}
