#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isDuplicate(string str) {
    stack<char> s;

    for (char ch : str) {
        if (ch != ')') {
            s.push(ch);
        } else { // closing bracket
            if (!s.empty() && s.top() == '(') {
                return true; // duplicate found
            } else {
                while (!s.empty() && s.top() != '(') {
                    s.pop();
                }
                if (!s.empty()) s.pop(); // pop the opening '('
            }
        }
    }

    return false; // no duplicates found
}

int main() {
    string str1 = "((a+b))";         // duplicate
    string str2 = "((a+b)+(c+d))";   // not duplicate

    cout << isDuplicate(str1) << endl; // 1
    cout << isDuplicate(str2) << endl; // 0

    return 0;
}
