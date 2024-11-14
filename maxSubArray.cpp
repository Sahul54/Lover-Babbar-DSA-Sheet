// Examples:

// Input: arr[] = [2, 3, -8, 7, -1, 2, 3]
// Output: 11
// Explanation: The subarray {7, -1, 2, 3} has the largest sum 11.
// Input: arr[] = [-2, -4]
// Output: -2
// Explanation: The subarray {-2} has the largest sum -2.
// Input: arr[] = [5, 4, 1, 7, 8]
// Output: 25
// Explanation: The subarray {5, 4, 1, 7, 8} has the largest sum 25.

#include<bits/stdc++.h>
using namespace std;

void maxSubarraySum(vector<int> &arr, int n) {
        // code here...
        int sum = 0;
        int maxi = arr[0];
        
        for(int i=0; i<n; i++){
        sum += arr[i];
        maxi = max(sum, maxi);
            
        if(sum<= 0){
            sum=0;
        }
    }
    cout<<maxi;
}
int main(){
    vector<int> arr{2, 3, -8, 7, -1, 2, 3};
    int n = arr.size();

    maxSubarraySum(arr, n);

    return 0;
}