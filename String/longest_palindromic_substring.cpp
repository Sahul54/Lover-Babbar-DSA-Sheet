#include <bits/stdc++.h>
using namespace std;

// Function to find the longest palindromic substring
string longestPalindrome(string s) {
    int n = s.size();
    if (n <= 1) return s; // Base case: single character or empty string

    int maxLength = 0; // Length of the longest palindrome
    int start = 0;     // Starting index of the longest palindrome

    // Helper lambda to expand around the center
    auto expandAroundCenter = [&](int left, int right) {
        while (left >= 0 && right < n && s[left] == s[right]) {
            left--;
            right++;
        }
        return right - left - 1; // Length of palindrome
    };

    // Iterate through the string to find palindromes
    for (int i = 0; i < n; i++) {
        // Odd-length palindrome
        int len1 = expandAroundCenter(i, i);
        // Even-length palindrome
        int len2 = expandAroundCenter(i, i + 1);

        // Find the longer palindrome
        int len = max(len1, len2);

        // Update maximum palindrome if found
        if (len > maxLength) {
            maxLength = len;
            start = i - (len - 1) / 2; // Calculate starting index
        }
    }

    // Return the longest palindrome substring
    return s.substr(start, maxLength);
}

// Main function for testing
int main() {
    string s;
    cout << "Enter the string: ";
    cin >> s;

    string result = longestPalindrome(s);
    cout << "Longest Palindromic Substring: " << result << endl;

    return 0;
}
