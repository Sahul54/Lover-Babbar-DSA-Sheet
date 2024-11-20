#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

string isSubset(vector<int>& a, vector<int>& b) {
    // Create a hash map to store the frequency of elements in array a
    unordered_map<int, int> freqMap;
    for (int num : a) {
        freqMap[num]++;
    }

    // Check if all elements of array b are present in array a
    for (int num : b) {
        if (freqMap[num] > 0) {
            freqMap[num]--; // Decrease the count for the element in the map
        } else {
            return "No"; // Element not found or not enough occurrences
        }
    }
    return "Yes"; // All elements of b are a subset of a
}

int main() {
    vector<int> a = {11, 7, 1, 13, 21, 3, 7, 3};
    vector<int> b = {11, 3, 7, 1, 7};

    cout << isSubset(a, b) << endl; // Output: Yes

    a = {1, 2, 3, 4, 4, 5, 6};
    b = {1, 2, 4};
    cout << isSubset(a, b) << endl; // Output: Yes

    a = {10, 5, 2, 23, 19};
    b = {19, 5, 3};
    cout << isSubset(a, b) << endl; // Output: No

    return 0;
}
