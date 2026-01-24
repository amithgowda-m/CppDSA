#include <iostream>
#include <map>
using namespace std;

int main(){
    map <int,string> m;
    m[101]="Amith";
    m[102]="gowda";
    m[103]="naveen";
    m[103]="praveen";
    for(auto it : m){
        cout<<it.first<<" "<<it.second<<endl;
    }
    return 0;

}