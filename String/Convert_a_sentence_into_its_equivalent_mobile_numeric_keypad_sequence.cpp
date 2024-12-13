#include <iostream>
#include <string>
using namespace std;

string printSequence(string S) {
    // Keypad mapping for A-Z and space
    string keypad[] = {
        "2", "22", "222",    // A, B, C
        "3", "33", "333",    // D, E, F
        "4", "44", "444",    // G, H, I
        "5", "55", "555",    // J, K, L
        "6", "66", "666",    // M, N, O
        "7", "77", "777", "7777",  // P, Q, R, S
        "8", "88", "888",    // T, U, V
        "9", "99", "999", "9999"  // W, X, Y, Z
    };
    
    string result = ""; // To store the output sequence

    for (char ch : S) {
        if (ch == ' ') {
            result += "0"; // Append '0' for space
        } else {
            result += keypad[ch - 'A']; // Append sequence for character
        }
    }
    return result;
}

int main() {
    string S = "HEY U";
    cout << printSequence(S) << endl; // Output: 4433999088
    return 0;
}
