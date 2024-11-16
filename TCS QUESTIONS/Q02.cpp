#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Function to determine if a word can fit on a line with the current space left
bool canFit(const string& word, int remainingSpace) {
    return word.length() <= remainingSpace;
}

// Function to calculate the maximum number of words that can fit in the given lines
int getMaxWords(const vector<string>& words, int N, int M) {
    int totalWords = words.size();
    int maxWords = 0;

    // Try all possible subsets of words
    for (int mask = 0; mask < (1 << totalWords); mask++) {
        vector<string> subset;
        for (int i = 0; i < totalWords; i++) {
            if (mask & (1 << i)) {
                subset.push_back(words[i]);
            }
        }

        // Check if the current subset can fit into the given lines
        int linesUsed = 1;
        int spaceLeft = M;
        bool fits = true;

        for (const auto& word : subset) {
            if (canFit(word, spaceLeft)) {
                // Place the word on the current line
                spaceLeft -= word.length();
                // Account for the space if not the first word on the line
                if (spaceLeft < M) spaceLeft--;
            } else if (canFit(word, M)) {
                // Move to the next line if the word fits on a new line
                linesUsed++;
                spaceLeft = M - word.length();
            } else {
                // Word doesn't fit in any line
                fits = false;
                break;
            }
        }

        // Update maxWords if this subset fits in the given lines
        if (fits && linesUsed <= N) {
            maxWords = max(maxWords, static_cast<int>(subset.size()));
        }
    }

    return maxWords;
}

int main() {
    // Input number of words
    int K;
    cin >> K;

    vector<string> words(K);
    for (int i = 0; i < K; i++) {
        cin >> words[i];
    }

    // Input N (lines) and M (max line length)
    int N, M;
    cin >> N >> M;

    // Calculate the maximum number of words that can fit
    int result = getMaxWords(words, N, M);

    // Output the result
    cout << result << endl;

    return 0;
}



#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

// 7-segment display for each character (0-9, +, -, %, =, *)
map<string, char> segmentToChar {
    {" _ | ||_|", '0'},
    {"     |  |", '1'},
    {" _  _||_ ", '2'},
    {" _  _| _|", '3'},
    {"   |_|  |", '4'},
    {" _  |_  _|", '5'},
    {" _ |_ |_|", '6'},
    {" _   |  |", '7'},
    {" _ |_||_|", '8'},
    {" _ |_| _|", '9'},
    {" _   |  |", '+'},
    {" _   |  _|", '-'},
    {" _  | |  ", '%'},
    {" _  _||_", '='},
    {" _  _|  ", '*'}
};

// Function to extract the character from a 3x3 display string
char getCharacterFromDisplay(string row1, string row2, string row3) {
    string segment = row1 + row2 + row3;
    if (segmentToChar.find(segment) != segmentToChar.end()) {
        return segmentToChar[segment];
    }
    return '?'; // If not found, return a question mark (error case)
}

int main() {
    int N;  // Length of the equation
    cin >> N;

    // Input the 3xN grid of segments
    vector<string> rows(3);
    for (int i = 0; i < 3; ++i) {
        cin >> rows[i];
    }

    // Parse the equation from the display (3x3 grid per character)
    vector<char> displayedEquation(N);
    for (int i = 0; i < N; ++i) {
        // Extract the 3x3 display for each character
        string row1 = rows[0].substr(i * 3, 3);
        string row2 = rows[1].substr(i * 3, 3);
        string row3 = rows[2].substr(i * 3, 3);
        
        // Get the corresponding character
        displayedEquation[i] = getCharacterFromDisplay(row1, row2, row3);
    }

    // Find the faulty character
    string equation(displayedEquation.begin(), displayedEquation.end());
    int faultPosition = -1;

    // Check the equation and find which character is faulty
    for (int i = 0; i < N; ++i) {
        // Create a temporary equation where the ith character is replaced
        string tempEquation = equation;
        tempEquation[i] = '?'; // Try removing the faulty character

        // Evaluate the equation (assuming a simple check)
        // Evaluate using some logic (sequential evaluation)
        // If it passes, return the position.
        if ( /* check if this fixes the equation */ ) {
            faultPosition = i + 1;
            break;
        }
    }

    // Print the faulty position
    cout << faultPosition << endl;

    return 0;
}
