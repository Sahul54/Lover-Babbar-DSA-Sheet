#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isParenthesisBalanced(string& s) {
   stack<char>st;
        for (char c : s) {
        if (c == '{' || c == '(' || c == '[') {
            st.push(c);
        } else if (c == '}' || c == ')' || c == ']') {
            if (st.empty()) {
                return false; // Unmatched closing bracket
            }
            char top = st.top();
            if ((c == '}' && top == '{') || 
                (c == ')' && top == '(') || 
                (c == ']' && top == '[')) {
                st.pop(); // Matched pair
            } else {
                return false; // Mismatched pair
            }
        }
    }

    return st.empty(); // True if all brackets matched
}

int main() {
    string s = "{[()]}{";
    if (isParenthesisBalanced(s)) {
        cout << "Balanced" << endl;
    } else {
        cout << "Not Balanced" << endl;
    }
    return 0;
}
