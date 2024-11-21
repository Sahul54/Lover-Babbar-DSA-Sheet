#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isTripletSum(vector<int>& arr, int target) {
    // Sort the array
    sort(arr.begin(), arr.end());

    // Loop through each element to consider it as the first element of the triplet
    for (int i = 0; i < arr.size() - 2; ++i) {
        // Initialize two pointers: left and right
        int left = i + 1;
        int right = arr.size() - 1;
        
        // Check for a valid triplet using two-pointer approach
        while (left < right) {
            int current_sum = arr[i] + arr[left] + arr[right];
            
            // If the sum equals the target, return true
            if (current_sum == target) {
                return true;
            }
            // If the sum is less than the target, move the left pointer to the right
            else if (current_sum < target) {
                left++;
            }
            // If the sum is greater than the target, move the right pointer to the left
            else {
                right--;
            }
        }
    }
    
    // No valid triplet was found
    return false;
}

int main() {
    vector<int> arr1 = {1, 4, 45, 6, 10, 8};
    int target1 = 13;
    cout << (isTripletSum(arr1, target1) ? "true" : "false") << endl;  // Expected: true

    vector<int> arr2 = {1, 2, 4, 3, 6, 7};
    int target2 = 10;
    cout << (isTripletSum(arr2, target2) ? "true" : "false") << endl;  // Expected: true

    return 0;
}
