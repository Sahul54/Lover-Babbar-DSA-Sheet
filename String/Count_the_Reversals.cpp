#include <iostream>
#include <string>
using namespace std;

int countRev(string s) {
    // If the length of the string is odd, it can't be balanced
    if (s.length() % 2 != 0) return -1;
    
    int open_count = 0;  // Tracks unbalanced opening brackets '{'
    int close_count = 0; // Tracks unbalanced closing brackets '}'

    // Traverse the string to count unbalanced brackets
    for (char ch : s) {
        if (ch == '{') {
            open_count++; // Count an opening bracket
        } else { // Closing bracket
            if (open_count > 0) {
                // Match the opening bracket with this closing bracket
                open_count--;
            } else {
                // Count this as an unbalanced closing bracket
                close_count++;
            }
        }
    }

    // Calculate the minimum number of reversals needed
    int reversals = (open_count + 1) / 2 + (close_count + 1) / 2;
    return reversals;
}

int main() {
    // Example usage
    string S1 = "}{{}}{{{";
    cout << "Input: " << S1 << "\nOutput: " << countRev(S1) << endl;

    string S2 = "{{}{{{}{{}}{{";
    cout << "Input: " << S2 << "\nOutput: " << countRev(S2) << endl;

    return 0;
}
