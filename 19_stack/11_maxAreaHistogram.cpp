#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int maxAreaHistogram(vector<int> height) {
    int n = height.size();
    vector<int> nsl(n);
    vector<int> nsr(n);
    stack<int> s;

    // Next Smaller Left
    nsl[0] = -1;
    s.push(0);
    for(int i = 1; i < n; i++) {
        while(!s.empty() && height[i] <= height[s.top()]) {
            s.pop();
        }
        nsl[i] = s.empty() ? -1 : s.top();
        s.push(i);
    }

    // Clear stack for NSR
    while(!s.empty()) s.pop();

    // Next Smaller Right
    nsr[n-1] = n;
    s.push(n-1);
    for(int i = n-2; i >= 0; i--) {
        while(!s.empty() && height[i] <= height[s.top()]) {
            s.pop();
        }
        nsr[i] = s.empty() ? n : s.top();
        s.push(i);
    }

    // Calculate max area
    int maxArea = 0;
    for(int i = 0; i < n; i++) {
        int width = nsr[i] - nsl[i] - 1;
        int area = width * height[i];
        maxArea = max(maxArea, area);
    }

    return maxArea;
}

int main() {
    vector<int> heights = {2, 1, 5, 6, 2, 3};
    cout << "Max Area: " << maxAreaHistogram(heights) << endl;
    return 0;
}
