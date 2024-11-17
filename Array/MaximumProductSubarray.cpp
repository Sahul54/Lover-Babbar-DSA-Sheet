// Examples

// Input: arr[] = [-2, 6, -3, -10, 0, 2]
// Output: 180
// Explanation: The subarray with maximum product is {6, -3, -10} with product = 6 * (-3) * (-10) = 180.
// Input: arr[] = [-1, -3, -10, 0, 60]
// Output: 60
// Explanation: The subarray with maximum product is {60}.
// Input: arr[] = [2, 3, 4]
// Output: 24
// Explanation: For an array with all positive elements, the result is product of all elements. 

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxProductSubarray(vector<int>& arr) {
    // If the array is empty, return 0
    if (arr.empty()) return 0;

    // Initialize the maximum product, minimum product, and result
    int max_prod = arr[0], min_prod = arr[0], result = arr[0];

    // Traverse the array from the second element
    for (int i = 1; i < arr.size(); i++) {
        // If the current number is negative, we swap max_prod and min_prod
        if (arr[i] < 0) {
            swap(max_prod, min_prod);
        }

        // Update max_prod and min_prod
        max_prod = max(arr[i], max_prod * arr[i]);
        min_prod = min(arr[i], min_prod * arr[i]);

        // Update the result
        result = max(result, max_prod);
    }

    return result;
}

int main() {
    vector<int> arr = {-2, 6, -3, -10, 0, 2};
    cout << "Maximum Product Subarray: " << maxProductSubarray(arr) << endl;

    arr = {-1, -3, -10, 0, 60};
    cout << "Maximum Product Subarray: " << maxProductSubarray(arr) << endl;

    return 0;
}
