#include <iostream>
#include <vector>
using namespace std;

void threeWayPartition(vector<int>& array, int a, int b) {
    int n = array.size();
    int low = 0, high = n - 1, i = 0;

    while (i <= high) {
        if (array[i] < a) {
            // Swap element smaller than `a` to the front
            swap(array[i], array[low]);
            low++;
            i++;
        } else if (array[i] > b) {
            // Swap element greater than `b` to the end
            swap(array[i], array[high]);
            high--;
        } else {
            // Element in range `[a, b]`
            i++;
        }
    }
}

int main() {
    vector<int> array = {1, 4, 3, 6, 2, 1};
    int a = 1, b = 3;

    threeWayPartition(array, a, b);

    // Output the modified array
    for (int num : array) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
