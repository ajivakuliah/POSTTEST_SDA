#include <iostream>
using namespace std;

void tukar(int **a, int **b) {
    int nilai = **a;
    **a = **b;
    **b = nilai;
}

int main() {
    int x, y;
    cout << "a: ";
    cin >> x;
    cout << "b  : ";
    cin >> y;

    cout << "\nSebelum: x = " << x << ", y = " << y << endl;

    int *px = &x, *py = &y;
    tukar(&px, &py);

    cout << "Sesudah : x = " << x << ", y = " << y << endl;

    return 0;
}
