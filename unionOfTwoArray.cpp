// Examples

// Input: a[] = [1, 2, 3, 4, 5], b[] = [1, 2, 3]
// Output: 5
// Explanation: 1, 2, 3, 4 and 5 are the elements which comes in the union setof both arrays. So count is 5.
// Input: a[] = [85, 25, 1, 32, 54, 6], b[] = [85, 2] 
// Output: 7
// Explanation: 85, 25, 1, 32, 54, 6, and 2 are the elements which comes in the union set of both arrays. So count is 7.
// Input: a[] = [1, 2, 1, 1, 2], b[] = [2, 2, 1, 2, 1] 
// Output: 2
// Explanation: We need to consider only distinct. So count is 2.

#include<bits/stdc++.h>
using namespace std;

int unionOfTwoArray(vector<int> a, vector<int> b){
        unordered_set<int> uniqueNo;
        for(int num: a) uniqueNo.insert(num);
        for(int num: b) uniqueNo.insert(num);

        return uniqueNo.size();
}

int main(){
    vector<int> a {1, 2, 3, 4, 5};
    vector<int> b {1, 2, 3, 4, 5};

    int ans = unionOfTwoArray(a,b);
    cout<<"ans: "<<ans;
    return 0;
}