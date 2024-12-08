#include <bits/stdc++.h>
using namespace std;

// Helper function for backtracking
void backtrack(string &s, vector<string> &result, string &current, vector<bool> &visited) {
    if (current.size() == s.size()) {
        result.push_back(current); // If the current permutation is complete, add to result
        return;
    }

    for (int i = 0; i < s.size(); i++) {
        // Skip if the character is already used or if it's a duplicate and the previous one wasn't used
        if (visited[i] || (i > 0 && s[i] == s[i - 1] && !visited[i - 1]))
            continue;

        // Mark as visited and include the character in the current permutation
        visited[i] = true;
        current.push_back(s[i]);

        // Recurse for the next characters
        backtrack(s, result, current, visited);

        // Backtrack: remove the character and mark it as not visited
        current.pop_back();
        visited[i] = false;
    }
}

// Function to return all unique permutations
vector<string> findPermutations(string s) {
    sort(s.begin(), s.end()); // Sort the string for lexicographical order
    vector<string> result;
    string current;
    vector<bool> visited(s.size(), false);

    backtrack(s, result, current, visited);
    return result;
}

// Main function for testing
int main() {
    string s;
    cout << "Enter the string: ";
    cin >> s;

    vector<string> permutations = findPermutations(s);
    cout << "Unique permutations are:\n";
    for (const auto &perm : permutations) {
        cout << perm << "\n";
    }

    return 0;
}
