// Examples:

// Input: arr[] = [2, 6, 1, 9, 4, 5, 3]
// Output: 6
// Explanation: The consecutive numbers here are 1, 2, 3, 4, 5, 6. These 6 numbers form the longest consecutive subsquence.
// Input: arr[] = [1, 9, 3, 10, 4, 20, 2]
// Output: 4
// Explanation: 1, 2, 3, 4 is the longest consecutive subsequence.
// Input: arr[] = [15, 13, 12, 14, 11, 10, 9]
// Output: 7
// Explanation: The longest consecutive subsequence is 9, 10, 11, 12, 13, 14, 15, which has a length of 7.

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int findLongestConsecutiveSubsequence(vector<int>& arr) {
    unordered_set<int> s(arr.begin(), arr.end());
    int maxLength = 0;

    for (int num : arr) {
        // Check if it's the start of a sequence
        if (s.find(num - 1) == s.end()) {
            int currentNum = num;
            int currentStreak = 1;

            // Count the length of the sequence
            while (s.find(currentNum + 1) != s.end()) {
                currentNum++;
                currentStreak++;
            }

            maxLength = max(maxLength, currentStreak);
        }
    }

    return maxLength;
}

int main() {
    vector<int> arr = {2, 6, 1, 9, 4, 5, 3};
    cout << "Length of the longest consecutive subsequence is: " 
         << findLongestConsecutiveSubsequence(arr) << endl;

    return 0;
}
