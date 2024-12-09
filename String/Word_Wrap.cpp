#include <bits/stdc++.h>
using namespace std;

int wordWrap(vector<int> &arr, int k) {
    int n = arr.size();

    // Store extra spaces in a 2D array
    vector<vector<int>> extraSpaces(n, vector<int>(n, 0));

    // Cost array for each line
    vector<vector<int>> cost(n, vector<int>(n, 0));

    // DP array to store the minimum cost
    vector<int> dp(n, INT_MAX);

    // Calculate extra spaces for all combinations
    for (int i = 0; i < n; i++) {
        extraSpaces[i][i] = k - arr[i];
        for (int j = i + 1; j < n; j++) {
            extraSpaces[i][j] = extraSpaces[i][j - 1] - arr[j] - 1; // Subtract word length and one space
        }
    }

    // Calculate cost for each line
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (extraSpaces[i][j] < 0) {
                cost[i][j] = INT_MAX; // Invalid line
            } else if (j == n - 1) {
                cost[i][j] = 0; // No cost for the last line
            } else {
                cost[i][j] = extraSpaces[i][j] * extraSpaces[i][j]; // Square of extra spaces
            }
        }
    }

    // Calculate the minimum cost using DP
    dp[n - 1] = 0; // Last word cost is zero
    for (int i = n - 2; i >= 0; i--) {
        for (int j = i; j < n; j++) {
            if (cost[i][j] != INT_MAX) {
                dp[i] = min(dp[i], cost[i][j] + dp[j + 1]);
            }
        }
    }

    return dp[0];
}

// Driver code
int main() {
    vector<int> arr = {3, 2, 2, 5};
    int k = 6;
    cout << "Minimum cost: " << wordWrap(arr, k) << endl;
    return 0;
}
