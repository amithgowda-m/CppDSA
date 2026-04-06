#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include<map>
using namespace std;

int main(){
    unordered_set<int> s;

    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(0);
    s.insert(0);
    s.insert(0);
    s.insert(0);
    s.insert(0);
    cout<<s.size()<<endl;

    if(s.find(3)!=s.end()){
        cout<<"3 exists\n";
    }else{
        cout<<"3 doesnt exists";
    }

    for(auto el : s){
        cout<<el<<" ";
    }
    return 0;
    
}