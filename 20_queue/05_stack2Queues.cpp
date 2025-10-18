#include <iostream>
#include <queue>
using namespace std;

class Stack {
    queue<int> q1, q2;

public:
    void push(int data) {
        // Step 1: Push the new element into q2
        q2.push(data);

        // Step 2: Move all elements from q1 to q2
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }

        // Step 3: Swap q1 and q2
        swap(q1, q2);
    }

    void pop() {
        if (!q1.empty())
            q1.pop();
    }

    int top() {
        if (!q1.empty())
            return q1.front();
        return -1; // or throw an exception
    }

    bool empty() {
        return q1.empty();
    }
};

int main() {
    Stack s;

    s.push(3);
    s.push(2);
    s.push(1);

    while (!s.empty()) {
        cout << s.top() << endl;
        s.pop();
    }

    return 0;
}
