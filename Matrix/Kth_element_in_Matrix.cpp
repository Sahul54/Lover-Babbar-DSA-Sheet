#include <bits/stdc++.h>
using namespace std;

#define MAX 100

int kthSmallest(int mat[MAX][MAX], int n, int k) {
    // Flatten the 2D matrix into a 1D vector
    vector<int> temp;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            temp.push_back(mat[i][j]);
        }
    }

    // Sort the 1D vector
    sort(temp.begin(), temp.end());

    // Return the k-th smallest element
    return temp[k - 1]; // k is 1-based indexing
}

// Main function for testing
int main() {
    int n, k;
    cout << "Enter the size of the matrix (N x N): ";
    cin >> n;

    int mat[MAX][MAX];
    cout << "Enter the elements of the matrix:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> mat[i][j];
        }
    }

    cout << "Enter the value of k: ";
    cin >> k;

    cout << "The " << k << "-th smallest element is: " << kthSmallest(mat, n, k) << endl;

    return 0;
}
