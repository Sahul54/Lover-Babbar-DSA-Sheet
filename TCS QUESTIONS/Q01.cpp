#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>

using namespace std;

// Map to convert tile names
int getTileIndex(const string& tile) {
    if (tile == "up") return 0;
    if (tile == "down") return 1;
    if (tile == "left") return 2;
    if (tile == "right") return 3;
    return -1; // Invalid tile ka name
}

int main() {
    int n;
    cin >> n;

    vector<int> instructions(n);
    for (int i = 0; i < n; i++) {
        string tile;
        cin >> tile;
        instructions[i] = getTileIndex(tile);
    }

    const int INF = INT_MAX;
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(4, vector<int>(4, INF)));

    // Initial state: Place feet on any two tiles
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (i != j) {
                dp[0][i][j] = 0; // No moves initially
            }
        }
    }

    // Fill DP table
    for (int i = 0; i < n; i++) {
        for (int left = 0; left < 4; left++) {
            for (int right = 0; right < 4; right++) {
                if (dp[i][left][right] == INF) continue;

                int next = instructions[i];

                // Move left foot
                if (left != next) {
                    dp[i + 1][next][right] = min(dp[i + 1][next][right], dp[i][left][right] + 1);
                } else {
                    dp[i + 1][left][right] = min(dp[i + 1][left][right], dp[i][left][right]);
                }

                // Move right foot
                if (right != next) {
                    dp[i + 1][left][next] = min(dp[i + 1][left][next], dp[i][left][right] + 1);
                } else {
                    dp[i + 1][left][right] = min(dp[i + 1][left][right], dp[i][left][right]);
                }
            }
        }
    }

    // Find the minimum moves to complete all instructions
    int result = INF;
    for (int left = 0; left < 4; left++) {
        for (int right = 0; right < 4; right++) {
            result = min(result, dp[n][left][right]);
        }
    }

    // Final result
    cout << result; 
    return 0;
}
