#include <iostream>
#include <stack>
using namespace std;

// Function to push an element at the bottom of a stack recursively
void pushAtBottom(stack<int> &st, int val) {
    // Base case: if stack is empty, push the value
    if (st.empty()) {
        st.push(val);
        return;
    }

    // Step 1: Pop the top element
    int topElement = st.top();
    st.pop();

    // Step 2: Recurse to reach the bottom
    pushAtBottom(st, val);

    // Step 3: Push the top element back
    st.push(topElement);
}

int main() {
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);

    cout << "Original Stack (top to bottom): 3 2 1" << endl;

    pushAtBottom(st, 99);

    cout << "Stack after pushing 99 at bottom (top to bottom): ";
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }

    return 0;
}
