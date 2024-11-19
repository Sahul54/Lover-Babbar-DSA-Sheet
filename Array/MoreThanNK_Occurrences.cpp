// Example 1:

// Input:
// N = 8
// arr = [3,1,2,2,1,2,3,3]
// k = 4
// Output: 
// 2
// Explanation: 
// In the given array, 3 and 2 are the only elements that appears more than n/k times.
// Example 2:

// Input:
// N = 4
// arr = [2,3,3,2]
// k = 3
// Output: 
// 2
// Explanation: In the given array, 3 and 2 are the only elements that appears more than n/k times. So the count of elements are 2.

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int countElementsMoreThanNbyK(int N, vector<int>& arr, int k) {
    // Step 1: Frequency count of elements
    unordered_map<int, int> freqMap;
    for (int i = 0; i < N; i++) {
        freqMap[arr[i]]++;
    }

    // Step 2: Calculate the threshold (n/k)
    int threshold = N / k;

    // Step 3: Count elements with frequency more than n/k
    int count = 0;
    for (auto& entry : freqMap) {
        if (entry.second > threshold) {
            count++;
        }
    }

    return count;
}

int main() {
    int N = 8;
    vector<int> arr = {3, 1, 2, 2, 1, 2, 3, 3};
    int k = 4;

    int result = countElementsMoreThanNbyK(N, arr, k);
    cout << "Count of elements with more than n/k occurrences: " << result << endl;

    return 0;
}
