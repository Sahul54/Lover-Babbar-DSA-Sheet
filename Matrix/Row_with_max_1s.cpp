#include <iostream>
#include <vector>
using namespace std;

// Function to find the row with the maximum number of 1s
int rowWithMax1s(vector<vector<int>>& arr) {
    int n = arr.size();    // Number of rows
    int m = arr[0].size(); // Number of columns
    
    int maxRowIndex = -1;  // To store the index of the row with the most 1s
    int j = m - 1;         // Start from the top-right corner

    for (int i = 0; i < n; i++) {
        // Move left while we encounter 1s
        while (j >= 0 && arr[i][j] == 1) {
            maxRowIndex = i; // Update the row index
            j--;             // Move left
        }
    }

    return maxRowIndex; // Return the row index with the most 1s
}

// Main function
int main() {
    vector<vector<int>> arr = {
        {0, 1, 1, 1},
        {0, 0, 1, 1},
        {1, 1, 1, 1},
        {0, 0, 0, 0}
    };

    int result = rowWithMax1s(arr);
    cout << "Row with maximum 1s: " << result << endl;

    return 0;
}
