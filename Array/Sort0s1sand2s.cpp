// Examples:

// Input: arr[] = [0, 1, 2, 0, 1, 2]
// Output: [0, 0, 1, 1, 2, 2]
// Explanation: 0s 1s and 2s are segregated into ascending order.

// Input: arr[] = [0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1]
// Output: [0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 2, 2]
// Explanation: 0s 1s and 2s are segregated into ascending order.

#include<bits/stdc++.h>
using namespace std;

void sortZeroOneTwo(vector<int>& arr, int n){
    // sort(arr.begin(), arr.end());

        int zeros = 0;
        int ones = 0;
        int twos = 0;
        
        for(int i=0; i<n; i++){
            if(arr[i] == 0){
                zeros++;
            }
            else if(arr[i] == 1){
                ones++;
            }
            else{
                twos++;
            }
        } 
        // ab count ho gya ho ga kitna 0,1 or 2 hai
        // ab sab insert kar do
        for(int i=0; i<zeros; i++){
            arr[i] = 0;
        }
        for(int i=zeros; i<zeros+ones; i++){
            arr[i] = 1;
        }
        for(int i=zeros+ones; i<zeros+ones+twos; i++){
            arr[i] = 2;
        }

    // Printing
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
}
int main(){
vector<int>arr {0, 1, 2, 0, 1, 2};
int n = arr.size();

sortZeroOneTwo(arr, n);
return 0;
}