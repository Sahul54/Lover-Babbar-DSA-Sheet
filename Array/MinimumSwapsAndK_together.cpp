#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int minSwaps(vector<int>& arr, int k) {
    int n = arr.size();
    
    // Step 1: Count elements <= k
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] <= k) {
            count++;
        }
    }

    // If no elements <= k, no swaps needed
    if (count == 0) return 0;

    // Step 2: Count bad elements in the first window
    int bad = 0;
    for (int i = 0; i < count; i++) {
        if (arr[i] > k) {
            bad++;
        }
    }

    // Step 3: Use sliding window to find the minimum bad count
    int minSwaps = bad;
    for (int i = 0, j = count; j < n; i++, j++) {
        // Remove the influence of the outgoing element
        if (arr[i] > k) {
            bad--;
        }
        // Add the influence of the incoming element
        if (arr[j] > k) {
            bad++;
        }
        // Update the minimum swaps
        minSwaps = min(minSwaps, bad);
    }

    return minSwaps;
}

int main() {
    vector<int> arr1 = {2, 1, 5, 6, 3};
    int k1 = 3;
    cout << "Minimum swaps for arr1: " << minSwaps(arr1, k1) << endl;

    vector<int> arr2 = {2, 7, 9, 5, 8, 7, 4};
    int k2 = 6;
    cout << "Minimum swaps for arr2: " << minSwaps(arr2, k2) << endl;

    vector<int> arr3 = {2, 4, 5, 3, 6, 1, 8};
    int k3 = 6;
    cout << "Minimum swaps for arr3: " << minSwaps(arr3, k3) << endl;

    return 0;
}
