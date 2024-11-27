#include <iostream>
#include <vector>
#include <algorithm> // for sort
using namespace std;

int findMedian(vector<int>& arr) {
    // Step 1: Sort the array
    sort(arr.begin(), arr.end());
    
    int n = arr.size();
    
    // Step 2: Check if the size of the array is odd or even
    if (n % 2 == 1) {
        // Odd size: median is the middle element
        return arr[n / 2];
    } else {
        // Even size: median is the floor of the average of two middle elements
        int mid1 = arr[n / 2];
        int mid2 = arr[n / 2 - 1];
        return (mid1 + mid2) / 2; // floor division in integer arithmetic
    }
}

int main() {
    vector<int> arr = {90, 100, 78, 89, 67};
    cout << "Median: " << findMedian(arr) << endl;

    return 0;
}
