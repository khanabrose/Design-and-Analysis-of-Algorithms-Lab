#include <iostream>
using namespace std;

int main() {
    const int SIZE = 5;
    int arr[SIZE] = {1, 2, 3, 4, 5};
    int result = 1;
    
    for (int i = 0; i < SIZE; ++i) {
        result *= arr[i];
    }
    
    cout << "Multiplication of array elements: " << result << endl;

    return 0;
}
