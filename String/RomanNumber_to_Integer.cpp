#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int romanToInt(string s) {
    // Map to store Roman numeral values
    unordered_map<char, int> roman = {
        {'I', 1}, {'V', 5}, {'X', 10}, 
        {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}
    };

    int n = s.size();
    int result = 0;

    for (int i = 0; i < n; i++) {
        // Check if the current character is smaller than the next character
        if (i < n - 1 && roman[s[i]] < roman[s[i + 1]]) {
            result -= roman[s[i]]; // Subtract the current value
        } else {
            result += roman[s[i]]; // Add the current value
        }
    }

    return result;
}

int main() {
    // Test cases
    string s1 = "V";
    cout << "Roman: " << s1 << " => Integer: " << romanToInt(s1) << endl;

    string s2 = "III";
    cout << "Roman: " << s2 << " => Integer: " << romanToInt(s2) << endl;

    string s3 = "IV";
    cout << "Roman: " << s3 << " => Integer: " << romanToInt(s3) << endl;

    return 0;
}
