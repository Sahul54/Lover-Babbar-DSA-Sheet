// Examples:

// Input: arr[][] = [[1,3],[2,4],[6,8],[9,10]]
// Output: [[1,4], [6,8], [9,10]]
// Explanation: In the given intervals we have only two overlapping intervals here, [1,3] and [2,4] which on merging will become [1,4]. Therefore we will return [[1,4], [6,8], [9,10]].
// Input: arr[][] = [[6,8],[1,9],[2,4],[4,7]]
// Output: [[1,9]]
// Explanation: In the given intervals all the intervals overlap with the interval [1,9]. Therefore we will return [1,9].


#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> mergeOverlap(vector<vector<int>>& arr) {
        // Code here
        int n = arr.size();
        sort(arr.begin(), arr.end());
        
        vector<vector<int>> ans;
        int start = 0;
        int end = 0;
        
        for(int i=0; i<n; i++){
            start = arr[i][0];
            end = arr[i][1];
            
            if(!ans.empty() && end <= ans.back()[1]){
                continue;
            }
            for(int j=i+1; j<n; j++){
                if(arr[j][0] <= end){
                    end = max(end, arr[j][1]);
                }
                else{
                    break;
                }
            }
            ans.push_back({start, end});
        }
        return ans;
    }
int main(){
    vector<vector<int>> arr {{1,3},{2,4},{6,8},{9,10}};
    mergeOverlap(arr);

    for(int i=0; i<arr.size(); i++){
        cout<<"{";
        for(int j=0; j<2; j++){
            cout<<arr[i][j]<<",";
        }
        cout<<"}"<<endl;
    }
return 0;
}