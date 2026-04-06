#include<iostream>
#include<set>
using namespace std;

int main(){
    set<int> s;
    s.insert(1);
    s.insert(3);
    for(auto el: s){
        cout<<el<<" ";
    }
    return 0;
}