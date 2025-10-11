#include <iostream>
#include <stack>
using namespace std;

// helper function to push element at bottom of stack
void pushAtBottom(stack<int> &st, int val) {
    if (st.empty()) {
        st.push(val);
        return;
    }
    int topElement = st.top();
    st.pop();
    pushAtBottom(st, val);
    st.push(topElement);
}

// main function to reverse stack recursively
void reverseStack(stack<int> &st) {
    if (st.empty()) return;

    int topElement = st.top();
    st.pop();

    reverseStack(st);       // reverse remaining stack
    pushAtBottom(st, topElement);  // insert top element at bottom
}

int main() {
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);

    cout << "Original stack (top to bottom): 4 3 2 1" << endl;

    reverseStack(st);

    cout << "Reversed stack (top to bottom): ";
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;

    return 0;
}
