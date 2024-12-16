#include <iostream>
#include <vector>
#include <string>
using namespace std;

int countPalindromicSubsequences(string s) {
    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));

    // Base case: Single characters are palindromic
    for (int i = 0; i < n; i++) {
        dp[i][i] = 1;
    }

    // Fill the DP table
    for (int length = 2; length <= n; length++) { // length of substring
        for (int i = 0; i <= n - length; i++) {
            int j = i + length - 1; // Ending index of the substring
            if (s[i] == s[j]) {
                dp[i][j] = dp[i+1][j] + dp[i][j-1] + 1;
            } else {
                dp[i][j] = dp[i+1][j] + dp[i][j-1] - dp[i+1][j-1];
            }
        }
    }

    // The result for the whole string
    return dp[0][n-1];
}

int main() {
    string s;
    cout << "Enter a string: ";
    cin >> s;

    int result = countPalindromicSubsequences(s);
    cout << "Number of palindromic subsequences: " << result << endl;

    return 0;
}
