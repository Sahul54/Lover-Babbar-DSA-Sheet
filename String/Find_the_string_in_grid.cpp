#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// Directions for 8 possible moves
const int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

// Function to check if the word exists starting at (x, y) in a specific direction
bool searchInDirection(const vector<vector<char>>& grid, int x, int y, const string& word, int dirX, int dirY) {
    int n = grid.size();
    int m = grid[0].size();
    int len = word.length();
    
    for (int k = 0; k < len; k++) {
        int newX = x + k * dirX;
        int newY = y + k * dirY;

        // Check if the indices are out of bounds or the characters do not match
        if (newX < 0 || newY < 0 || newX >= n || newY >= m || grid[newX][newY] != word[k]) {
            return false;
        }
    }
    return true;
}

vector<vector<int>> searchWord(vector<vector<char>>& grid, const string& word) {
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> result;

    // Traverse the grid
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            // If the starting character matches
            if (grid[i][j] == word[0]) {
                // Check all 8 directions
                for (int d = 0; d < 8; d++) {
                    if (searchInDirection(grid, i, j, word, dx[d], dy[d])) {
                        result.push_back({i, j});
                        break; // Add the starting point only once
                    }
                }
            }
        }
    }

    // Sort the result in lexicographical order
    sort(result.begin(), result.end());
    return result;
}

int main() {
    vector<vector<char>> grid1 = {
        {'a', 'b', 'c'},
        {'d', 'r', 'f'},
        {'g', 'h', 'i'}
    };
    string word1 = "abc";
    vector<vector<int>> result1 = searchWord(grid1, word1);
    cout << "Occurrences for word \"" << word1 << "\": ";
    for (const auto& coords : result1) {
        cout << "{" << coords[0] << "," << coords[1] << "} ";
    }
    cout << endl;

    vector<vector<char>> grid2 = {
        {'a', 'b', 'a', 'b'},
        {'a', 'b', 'e', 'b'},
        {'e', 'b', 'e', 'b'}
    };
    string word2 = "abe";
    vector<vector<int>> result2 = searchWord(grid2, word2);
    cout << "Occurrences for word \"" << word2 << "\": ";
    for (const auto& coords : result2) {
        cout << "{" << coords[0] << "," << coords[1] << "} ";
    }
    cout << endl;

    return 0;
}
