#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to calculate the factorial of a number
vector<int> factorial(int n) {
    vector<int> result;
    result.push_back(1); // Initialize with 1 since 0! = 1 and 1! = 1

    // Multiply numbers from 2 to n with the current result stored in the vector
    for (int i = 2; i <= n; ++i) {
        int carry = 0;

        // Multiply each digit in the vector with `i`
        for (int j = 0; j < result.size(); ++j) {
            int product = result[j] * i + carry;
            result[j] = product % 10; // Store the last digit of the product
            carry = product / 10;    // Carry the remaining part
        }

        // Handle remaining carry
        while (carry) {
            result.push_back(carry % 10);
            carry /= 10;
        }
    }

    // The result is stored in reverse order
    reverse(result.begin(), result.end());
    return result;
}

int main() {
    int n; 
    cout << "Enter a number to calculate its factorial: ";
    cin >> n; // Input from user

    vector<int> result = factorial(n);

    // Print the factorial
    cout << "Factorial of " << n << " is: ";
    for (int digit : result) {
        cout << digit;
    }
    cout << endl;

    return 0;
}
