#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isValid(string str) {
    stack<char> s;

    for (int i = 0; i < str.size(); i++) {
        char ch = str[i];

        if (ch == '(' || ch == '[' || ch == '{') {
            s.push(ch);
        } else { // closing bracket
            if (s.empty()) {
                return false; // insufficient opening brackets
            }

            char top = s.top();
            if ((top == '(' && ch == ')') || (top == '[' && ch == ']') || (top == '{' && ch == '}')) {
                s.pop();
            } else {
                return false; // mismatch
            }
        }
    }

    return s.empty();
}

int main() {
    string str1 = "([}])";  // invalid
    string str2 = "([{}])";  // valid

    cout << isValid(str1) << endl; // 0 (false)
    cout << isValid(str2) << endl; // 1 (true)

    return 0;
}
