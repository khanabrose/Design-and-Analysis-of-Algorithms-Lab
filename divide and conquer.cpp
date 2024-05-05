#include <iostream>
#include <vector>
using namespace std;

// Function implementing binary search using divide and conquer
int binarySearch(const vector<int>& arr, int target, int left, int right) {
    if (left > right) {
        return -1; // Element not found
    }

    int mid = left + (right - left) / 2;

    if (arr[mid] == target) {
        return mid; // Element found
    } else if (arr[mid] < target) {
        return binarySearch(arr, target, mid + 1, right); // Search in the right half
    } else {
        return binarySearch(arr, target, left, mid - 1); // Search in the left half
    }
}

int main() {
    vector<int> arr = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int target = 11;

    int index = binarySearch(arr, target, 0, arr.size() - 1);

    if (index != -1) {
        cout << "Element found at index " << index << endl;
    } else {
        cout << "Element not found in the array." << endl;
    }

    return 0;
}
