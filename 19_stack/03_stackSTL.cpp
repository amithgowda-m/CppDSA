#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main(){
    stack<int> s;

    s.push(2);
    s.push(1);
    s.push(0);

    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }

    cout<<endl;
    return 0;
}