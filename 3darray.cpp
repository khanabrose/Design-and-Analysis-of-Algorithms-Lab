#include <iostream>
using namespace std;

int main() {
    const int X = 2;
    const int Y = 2;
    const int Z = 2;
    int arr[X][Y][Z];

    cout << "Enter " << X * Y * Z << " integers for a 2x2x2 3D array:" << endl;
    for (int i = 0; i < X; i++) {
        for (int j = 0; j < Y; j++) {
            for (int k = 0; k < Z; k++) {
                cin >> arr[i][j][k];
            }
        }
    }

    cout << "Entered 3D array is:" << endl;
    for (int i = 0; i < X; i++) {
        for (int j = 0; j < Y; j++) {
            for (int k = 0; k < Z; k++) {
                cout << arr[i][j][k] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    return 0;
}
