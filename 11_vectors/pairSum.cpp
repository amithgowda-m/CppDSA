#include <iostream>
#include <vector>
using namespace std;

vector<int> PairSum(vector<int> arr, int target) {
    int start = 0, end = arr.size() - 1;
    int curSum = 0;
    vector<int> ans;

    while (start < end) {
        curSum = arr[start] + arr[end];
        if (curSum == target) {
            ans.push_back(start);
            ans.push_back(end);
            return ans;
        } else if (curSum > target) {
            end--;
        } else {
            start++;
        }
    }

    return ans;
}

int main() {
    vector<int> vec = {2, 7, 11, 15};
    int target = 9;

    vector<int> ans = PairSum(vec, target);

    if (ans.empty()) {
        cout << "No pair found" << endl;
    } else {
        cout << ans[0] << " " << ans[1] << endl;
    }

    return 0;
}
