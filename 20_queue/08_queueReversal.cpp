#include <iostream>
#include <stack>
#include <queue>
using namespace std;

void revers(queue <int> &q){
    stack<int> s;
    while(!q.empty()){
        s.push(q.front());
        q.pop();
    }

    while(!s.empty()){
        q.push(s.top());
        s.pop();
    }

}

int main(){
    queue<int> q;
    for (int i = 00; i < 5; i++){
        q.push(i);
    }
    revers(q);
    for (int i = 00; i < 5; i++){
        cout<<q.front()<<endl;
        q.pop();
    }
    cout<<endl;
    return 0;
}
