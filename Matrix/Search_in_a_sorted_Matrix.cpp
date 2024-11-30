#include <iostream>
#include <vector>
using namespace std;

bool searchInMatrix(vector<vector<int>> &mat, int x) {
    int rows = mat.size();
    int cols = mat[0].size();

    int low = 0, high = rows * cols - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        int row = mid / cols;   // Map 1D index to row
        int col = mid % cols;   // Map 1D index to column
        int midElement = mat[row][col];

        if (midElement == x) {
            return true;  // Found the element
        } else if (midElement < x) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return false; // Element not found
}

int main() {
    vector<vector<int>> mat = {{3, 30, 38}, {40, 43, 60}, {69, 72, 78}};
    int x = 62;

    if (searchInMatrix(mat, x)) {
        cout << "true\n";
    } else {
        cout << "false\n";
    }

    return 0;
}
