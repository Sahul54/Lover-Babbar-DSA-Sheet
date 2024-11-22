#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int trap(vector<int>& arr) {
    int n = arr.size();
    if (n <= 2) return 0;  // No water can be trapped if there are fewer than 3 blocks
    
    int left = 0, right = n - 1;
    int left_max = 0, right_max = 0;
    int trappedWater = 0;
    
    while (left <= right) {
        if (arr[left] < arr[right]) {
            if (arr[left] >= left_max) {
                left_max = arr[left];
            } else {
                trappedWater += left_max - arr[left];
            }
            left++;
        } else {
            if (arr[right] >= right_max) {
                right_max = arr[right];
            } else {
                trappedWater += right_max - arr[right];
            }
            right--;
        }
    }
    
    return trappedWater;
}

int main() {
    vector<int> arr = {3, 0, 0, 2, 0, 4};
    cout << "Water trapped: " << trap(arr) << endl;  // Output: 10
    return 0;
}
