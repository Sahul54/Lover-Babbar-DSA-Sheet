#include <iostream>
#include <string>
using namespace std;

bool searchPattern(string& txt, string& pat) {
    if (txt.find(pat) != string::npos) {
        return true;
    }
    return false;
}

int main() {
    string txt = "hello world";
    string pat = "world";
    
    if (searchPattern(txt, pat)) {
        cout << "Pattern found!" << endl;
    } else {
        cout << "Pattern not found." << endl;
    }

    return 0;
}
