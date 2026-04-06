#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<double,int> p1, pair<double,int> p2) {
    return p1.first > p2.first; 
}

double fractionalKnapsack(vector<int> val, vector<int> wt, int W) {
    int n = val.size();
    vector<pair<double,int>> ratio(n);

    for (int i = 0; i < n; i++) {
        double r = (double)val[i] / wt[i];
        ratio[i] = {r, i};
    }

    sort(ratio.begin(), ratio.end(), compare);

    double ans = 0.0;

    for (int i = 0; i < n; i++) {
        int idx = ratio[i].second;
        if (wt[idx] <= W) {
            ans += val[idx];
            W -= wt[idx];
        } else {
            ans += ratio[i].first * W; 
            break; // bag full
        }
    }
    return ans;
}

int main() {
    vector<int> val = {60, 100, 120};
    vector<int> wt  = {10, 20, 30};
    int W = 50;

    cout << fractionalKnapsack(val, wt, W) << endl;
    return 0;
}
