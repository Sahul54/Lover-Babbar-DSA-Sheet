// Examples:

// Input: arr = [3, 2, 1, 56, 10000, 167]
// Output: 1 10000
// Explanation: minimum and maximum elements of array are 1 and 10000.

// Input: arr = [1, 345, 234, 21, 56789]
// Output: 1 56789
// Explanation: minimum and maximum element of array are 1 and 56789.

// Input: arr = [56789]
// Output: 56789 56789
// Explanation: Since the array contains only one element so both min & max are same.

#include<bits/stdc++.h>
using namespace std;

// void findMinAndMax(int arr[], int n){
//     sort(arr, arr+n);

//     cout<<"Min No: "<<arr[0]<<endl;
//     cout<<"Max No: "<<arr[n-1]<<endl;
// }

void findMinAndMax(int arr[], int n){
    int maxa = INT_MIN;
    int mini = INT_MAX;

    for(int i=0; i<n; i++){
        if(mini > arr[i]){
            mini = arr[i];
        }
    }
    cout<<mini;

    for(int i=0; i<n; i++){
        if(maxa < arr[i]){
            maxa = arr[i];
        }
    }
    cout<<mini;
}

int main(){
    int arr[] = {3, 2, 1, 56, 10000, 167};
    int n = sizeof(arr) / sizeof(arr[0]);

    findMinAndMax(arr,n);
return 0;
}