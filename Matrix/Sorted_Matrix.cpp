#include <bits/stdc++.h>
using namespace std;

// Function to sort a given matrix
vector<vector<int>> sortedMatrix(int N, vector<vector<int>> Mat) {
    // Step 1: Flatten the matrix into a 1D vector
    vector<int> temp;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            temp.push_back(Mat[i][j]);
        }
    }

    // Step 2: Sort the 1D vector
    sort(temp.begin(), temp.end());

    // Step 3: Rebuild the sorted matrix
    int idx = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            Mat[i][j] = temp[idx++];
        }
    }

    return Mat;
}

// Main function for testing
int main() {
    int N;
    cout << "Enter the size of the matrix (N x N): ";
    cin >> N;

    vector<vector<int>> Mat(N, vector<int>(N));
    cout << "Enter the elements of the matrix:" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> Mat[i][j];
        }
    }

    vector<vector<int>> result = sortedMatrix(N, Mat);

    cout << "Sorted Matrix:" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
