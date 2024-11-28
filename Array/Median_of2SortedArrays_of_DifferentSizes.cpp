#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

double findMedianSortedArrays(const vector<int>& a, const vector<int>& b) {
    // Ensure the first array is smaller for binary search
    if (a.size() > b.size()) {
        return findMedianSortedArrays(b, a);
    }

    int m = a.size();
    int n = b.size();
    int low = 0, high = m;

    while (low <= high) {
        int partitionA = (low + high) / 2;
        int partitionB = (m + n + 1) / 2 - partitionA;

        // Get max and min values at partition boundaries
        int maxLeftA = (partitionA == 0) ? INT_MIN : a[partitionA - 1];
        int minRightA = (partitionA == m) ? INT_MAX : a[partitionA];

        int maxLeftB = (partitionB == 0) ? INT_MIN : b[partitionB - 1];
        int minRightB = (partitionB == n) ? INT_MAX : b[partitionB];

        // Check if partitions are valid
        if (maxLeftA <= minRightB && maxLeftB <= minRightA) {
            // Calculate median
            if ((m + n) % 2 == 0) {
                return (max(maxLeftA, maxLeftB) + min(minRightA, minRightB)) / 2.0;
            } else {
                return max(maxLeftA, maxLeftB);
            }
        } else if (maxLeftA > minRightB) {
            // Move partitionA to the left
            high = partitionA - 1;
        } else {
            // Move partitionA to the right
            low = partitionA + 1;
        }
    }

    // If no median found (invalid input)
    throw invalid_argument("Input arrays are not valid!");
}

int main() {
    vector<int> a = {1, 5, 9};
    vector<int> b = {2, 3, 6, 7};

    cout << "Median: " << findMedianSortedArrays(a, b) << endl;

    return 0;
}
