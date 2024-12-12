#include<bits/stdc++.h>
using namespace std;

vector <int> search(string pattern, string text){
        //code here.
        int n = text.size();
        int k = pattern.size();
        vector<int> ans;
            
        for(int i=0; i<n; i++){
            if(pattern == text.substr(i, k)){
                ans.push_back(i+1);
           }
        }
        return ans;
    }

int main(){
    string text = "geeksforgeeks";
    string pattern = "geek";

    vector<int> result = search(pattern, text);
    
    if(result.empty()){
        cout<<"not found pattern";
    }
    else{
        cout<<"[ ";
        for(int it : result){
            cout<<it<<",";
        }
        cout<<"]";
    }
    
return 0;
}