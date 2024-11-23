#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int smallestSubWithSum(int x, vector<int>& arr) {
    int n = arr.size(); // Fix: Initialize `n` as the size of the array
    int start = 0, end = 0;
    int curr_sum = 0;
    int minLength = INT_MAX;

    // Sliding window approach
    while (end < n) {
        curr_sum += arr[end];

        // Shrink the window until the sum becomes smaller or equal to `x`
        while (curr_sum > x) {
            minLength = min(minLength, end - start + 1);
            curr_sum -= arr[start];
            start++;
        }

        // Expand the window
        end++;
    }

    // Return 0 if no valid subarray is found
    return (minLength == INT_MAX) ? 0 : minLength;
}

int main() {
    vector<int> arr = {1, 4, 45, 6, 0, 19};
    int x = 51;

    cout << "Smallest subarray length with sum greater than " << x << " is: " 
         << smallestSubWithSum(x, arr) << endl;

    return 0;
}
