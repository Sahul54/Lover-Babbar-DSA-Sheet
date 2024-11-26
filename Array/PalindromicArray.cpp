#include <vector>
#include <stack>
using namespace std;

bool PalinArray(vector<int> &arr) {
    // Iterate over each number in the array
    for (int num : arr) {
        stack<int> st;
        int original = num;

        // Push all digits of the number into the stack
        while (num > 0) {
            st.push(num % 10);
            num /= 10;
        }

        num = original; // Reset num to the original number
        int reversed = 0;
        int multiplier = 1;

        // Pop digits from the stack to reverse the number
        while (!st.empty()) {
            reversed += st.top() * multiplier;
            st.pop();
            multiplier *= 10;
        }

        // Check if the original number and reversed number are the same
        if (original != reversed) {
            return false; // Return false if any number is not a palindrome
        }
    }

    return true; // Return true if all numbers are palindromes
}
