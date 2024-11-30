#include <iostream>
#include <vector>
using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> result;

    if (matrix.empty()) return result;

    int top = 0; // Top boundary
    int bottom = matrix.size() - 1; // Bottom boundary
    int left = 0; // Left boundary
    int right = matrix[0].size() - 1; // Right boundary

    while (top <= bottom && left <= right) {
        // Traverse from left to right along the top row
        for (int i = left; i <= right; ++i)
            result.push_back(matrix[top][i]);
        ++top; // Move the top boundary down

        // Traverse from top to bottom along the rightmost column
        for (int i = top; i <= bottom; ++i)
            result.push_back(matrix[i][right]);
        --right; // Move the right boundary left

        if (top <= bottom) {
            // Traverse from right to left along the bottom row
            for (int i = right; i >= left; --i)
                result.push_back(matrix[bottom][i]);
            --bottom; // Move the bottom boundary up
        }

        if (left <= right) {
            // Traverse from bottom to top along the leftmost column
            for (int i = bottom; i >= top; --i)
                result.push_back(matrix[i][left]);
            ++left; // Move the left boundary right
        }
    }

    return result;
}

int main() {
    vector<vector<int>> matrix = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };

    vector<int> result = spiralOrder(matrix);

    cout << "Spiral Traversal: ";
    for (int num : result)
        cout << num << " ";
    cout << endl;

    return 0;
}