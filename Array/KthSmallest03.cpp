// Examples :

// Input: arr[] = [7, 10, 4, 3, 20, 15], k = 3
// Output:  7
// Explanation: 3rd smallest element in the given array is 7.

// Input: arr[] = [2, 3, 1, 20, 15], k = 4 
// Output: 15
// Explanation: 4th smallest element in the given array is 15.

#include<bits/stdc++.h>
using namespace std;

// int kthSmallest(vector<int> &arr, int k, int n){
//     sort(arr.begin(), arr.end());

//     return arr[k-1];
// }

int kthSmallest(vector<int> &arr, int k, int n){
    priority_queue<int>pq;

    for(int i=0; i<n; i++){
        if(pq.size() < k){
            pq.push(arr[i]);
        }
        else{
            if(pq.top() > arr[i]){
                pq.pop();
                pq.push(arr[i]);
            }
        }
    }
    return pq.top();
}
int main(){
    vector<int> arr{7, 10, 4, 3, 20, 15};
    int k = 3;
    int n = arr.size();

    int ans = kthSmallest(arr, k, n);
    cout<<"Kth Smallest No: "<< ans;
return 0;
}