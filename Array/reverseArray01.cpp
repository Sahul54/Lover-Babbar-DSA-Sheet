// Examples:

// Input: s = "Geeks"
// Output: "skeeG"

// Input: s = "for"
// Output: "rof"

// Input: s = "a"
// Output: "a"

// Link : https://www.geeksforgeeks.org/problems/reverse-a-string/1

#include<bits/stdc++.h>
using namespace std;

// void reverseStr(string &s){
//     int n = s.length();

//     reverse(s.begin(), s.end());
//     cout<<"Reverse String : "<<s<<endl;
// }

// void reverseStr(string &s){
//     int n = s.length();
//     int l = 0;
//     int r = n-1;

//     while(l<=r){
//         swap(s[l], s[r]);
//         // Yaha bhul jate ho
//         l++;
//         r--;
//     }
//     cout<<"Reverse String : "<<s<<endl;
// }


void reverseStr(string &s){
    int n = s.length();
    int l = 0;
    int r = n-1;

    string temp = "";
    while(l<=r){
        temp = s[l];
        s[l] = s[r];
        s[r] = temp[0];
        l++;
        r--;
    }
    cout<<"Reverse String : "<<s<<endl;
}

int main(){
    string s = "Geeks";
    reverseStr(s);
return 0;
}