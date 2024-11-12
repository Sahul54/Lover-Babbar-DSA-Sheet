// Examples:

// Input: arr = [1, 2, 3, 4, 5]
// Output: [5, 1, 2, 3, 4]
// Explanation: If we rotate arr by one position in clockwise 5 come to the front and remaining those are shifted to the end.
// Input: arr = [9, 8, 7, 6, 4, 2, 1, 3]
// Output: [3, 9, 8, 7, 6, 4, 2, 1]
// Explanation: After rotating clock-wise 3 comes in first position.

#include <iostream>
#include <vector>

using namespace std;

void rotate(vector<int> &arr) {
    int n = arr.size();
    int temp = arr[n - 1]; // Store the last element

    // Shift elements to the right by one position
    for (int i = n - 1; i > 0; i--) {
        arr[i] = arr[i - 1];
    }

    arr[0] = temp; // Place the last element at the front
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};

    cout << "Original array: ";
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Rotate the array
    rotate(arr);

    cout << "Array after rotation: ";
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
