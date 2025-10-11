#include <iostream>
#include <stack>
#include <string>
using namespace std;

string reverseString(string str) {
    stack<char> st;

    // Push all characters into stack
    for (char ch : str)
        st.push(ch);

    // Pop all characters to build reversed string
    string reversed = "";
    while (!st.empty()) {
        reversed += st.top();
        st.pop();
    }

    return reversed;
}

int main() {
    string s = "AmithGowda";
    cout << "Original String: " << s << endl;

    string reversed = reverseString(s);
    cout << "Reversed String: " << reversed << endl;

    return 0;
}
