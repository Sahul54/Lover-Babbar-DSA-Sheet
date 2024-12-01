#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int median(vector<vector<int>> &mat) {
    int rows = mat.size();
    int cols = mat[0].size();
    
    int low = INT_MAX, high = INT_MIN;
    
    // Find the minimum and maximum elements in the matrix
    for (int i = 0; i < rows; i++) {
        low = min(low, mat[i][0]);         // Minimum of the first column
        high = max(high, mat[i][cols - 1]); // Maximum of the last column
    }
    
    int desired = (rows * cols + 1) / 2; // Median position in sorted order
    
    // Binary search on the range [low, high]
    while (low < high) {
        int mid = low + (high - low) / 2;
        int count = 0;

        // Count elements less than or equal to mid
        for (int i = 0; i < rows; i++) {
            count += upper_bound(mat[i].begin(), mat[i].end(), mid) - mat[i].begin();
        }
        
        if (count < desired)
            low = mid + 1; // Median lies in the upper half
        else
            high = mid; // Median lies in the lower half
    }
    
    return low;
}

int main() {
    vector<vector<int>> mat = {
        {1, 3, 5},
        {2, 6, 9},
        {3, 6, 9}
    };

    cout << "Median: " << median(mat) << endl;
    return 0;
}
