#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int editDistance(string s1, string s2) {
    int m = s1.length();
    int n = s2.length();
    
    // Create a dp table
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    
    // Fill the dp table
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            // Base cases
            if (i == 0)
                dp[i][j] = j; // Insert all characters of s2
            else if (j == 0)
                dp[i][j] = i; // Remove all characters of s1
            else if (s1[i - 1] == s2[j - 1])
                dp[i][j] = dp[i - 1][j - 1]; // Characters match, no operation needed
            else
                dp[i][j] = 1 + min({dp[i - 1][j - 1], // Replace
                                    dp[i][j - 1],     // Insert
                                    dp[i - 1][j]});   // Remove
        }
    }
    
    return dp[m][n];
}

int main() {
    string s1 = "geek", s2 = "gesek";
    cout << "Minimum operations required: " << editDistance(s1, s2) << endl;
    return 0;
}
