// Move all negative elements to end

// Examples:

// Input : arr[] = [1, -1, 3, 2, -7, -5, 11, 6 ]
// Output : [1, 3, 2, 11, 6, -1, -7, -5]
// Explanation: By doing operations we separated the integers without changing the order.

// Input : arr[] = [-5, 7, -3, -4, 9, 10, -1, 11]
// Output : [7, 9, 10, 11, -5, -3, -4, -1]

#include <iostream>
#include <vector>
using namespace std;

void segregateElements(vector<int>& arr) {
    int n = arr.size();
    vector<int> positive;
    vector<int> negative;
    
    // Separate positive and negative numbers
    for(int i = 0; i < n; i++) {
        if(arr[i] >= 0) {
            positive.push_back(arr[i]);
        } else {
            negative.push_back(arr[i]);
        }
    }
    
    // Combine the positive and negative elements back into arr
    int index = 0;
    for(int i = 0; i < positive.size(); i++) {
        arr[index++] = positive[i];
    }
    for(int i = 0; i < negative.size(); i++) {
        arr[index++] = negative[i];
    }
}

int main() {
    vector<int> arr = {1, -2, 3, -4, -5, 6, 7, -8, 9};

    cout << "Original Array: ";
    for(int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    segregateElements(arr);

    cout << "Array after segregation: ";
    for(int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
