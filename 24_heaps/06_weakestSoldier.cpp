#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Row {
public:
    int count;
    int idx;

    Row(int count, int idx) {
        this->count = count;
        this->idx = idx;
    }
};

// Custom comparator for min-heap
struct Compare {
    bool operator()(const Row &a, const Row &b) {
        if (a.count == b.count) {
            return a.idx > b.idx; // smaller index first
        }
        return a.count > b.count; // fewer soldiers first
    }
};

void weakestSold(vector<vector<int>> &matrix, int k) {
    priority_queue<Row, vector<Row>, Compare> pq;

    for (int i = 0; i < matrix.size(); i++) {
        int count = 0;
        for (int j = 0; j < matrix[i].size() && matrix[i][j] == 1; j++) {
            count++;
        }
        pq.push(Row(count, i));
    }

    for (int i = 0; i < k && !pq.empty(); i++) {
        cout << "Row: " << pq.top().idx << endl;
        pq.pop();
    }
}

int main() {
    vector<vector<int>> matrix{
        {1,0,0,0},
        {1,1,1,1},
        {1,0,0,0},
        {1,0,0,0}
    };

    weakestSold(matrix, 2);

    return 0;
}
