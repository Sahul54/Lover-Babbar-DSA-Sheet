// Examples:

// Input: a[] = [2, 4, 7, 10], b[] = [2, 3]
// Output:
// 2 2 3 4
// 7 10
// Explanation: After merging the two non-decreasing arrays, we get, 2 2 3 4 7 10
// Input: a[] = [1, 5, 9, 10, 15, 20], b[] = [2, 3, 8, 13]
// Output:
// 1 2 3 5 8 9
// 10 13 15 20
// Explanation: After merging two sorted arrays we get 5 10 12 18 20.
// Input: a[] = [0, 1], b[] = [2, 3]
// Output:
// 0 1
// 2 3
// Explanation: After merging two sorted arrays we get 0 1 2 3.

#include<bits/stdc++.h>
using namespace std;

void mergeArrays(vector<int>& a, vector<int>& b) {
        // code here
        int n = a.size();
        int m = b.size();
        
        int left = n-1;
        int right = 0;
        
        while(left >= 0 && right < m){
            if(a[left] > b[right]){
                swap(a[left], b[right]);
            }
            left--;
            right++;
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        for(int i=0;i<n;i++){
            cout<<a[i]<<" ";
        }
        cout<<endl;
        for(int i=0;i<m;i++){
            cout<<b[i]<<" ";
        }
    }

int main(){
vector<int> a{2, 4, 7, 10};
vector<int> b{2, 3};

mergeArrays(a,b);

return 0;
}