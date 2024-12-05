#include <bits/stdc++.h>
using namespace std;

// Function to generate the nth row of the Look-and-Say pattern
string lookandsay(int n) {
    // Base case: the first row is "1"
    string result = "1";

    // Generate rows from 2 to n
    for (int i = 2; i <= n; i++) {
        string current = ""; // To store the current row
        int count = 1;       // To count occurrences of the current digit

        // Traverse the previous row
        for (int j = 1; j < result.size(); j++) {
            if (result[j] == result[j - 1]) {
                // Increment count if the same digit is repeated
                count++;
            } else {
                // Append the count and the digit to the current row
                current += to_string(count) + result[j - 1];
                count = 1; // Reset count for the next digit
            }
        }

        // Add the last group to the current row
        current += to_string(count) + result.back();

        // Update result to the current row for the next iteration
        result = current;
    }

    return result;
}

// Main function for testing
int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    cout << "The " << n << "th row of the Look-and-Say pattern is: " << lookandsay(n) << endl;

    return 0;
}
