#include <iostream>
#include <list>
#include <iterator>
using namespace std;

int main(){
    list <int> ll;
    ll.push_back(4);
    ll.push_front(2);
    ll.push_back(3);
    ll.push_front(1);

    list<int> ::iterator itr;
    for(itr = ll.begin();itr!=ll.end();itr++){
        cout<<(*itr)<<"->";
    }
    cout<<"NULL\n";
    cout<<ll.size()<<endl;
    cout<<ll.front()<<endl;
    cout<<ll.back()<<endl;
    return 0;
}