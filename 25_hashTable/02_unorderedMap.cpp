#include <iostream>
#include <unordered_map>
#include <map>
using namespace std;

int main(){
    unordered_map<string,int> m;    //key, value
    m["India"]=1;//interrnally string is getting converted into a int value using hash function here
    m["China"]=2;
    m["US"]=3;
    m["France"]=4;
    for(pair<string,int> country : m){
        cout<<country.first<<" : "<<country.second<<endl;
    }//prints in different order
    if(m.count("US")){//count does search operation
        cout<<"US exists\n";
    }else{
        cout<<"US doesnt exists";
    }

    m.erase("US");
    for(pair<string,int> country : m){
        cout<<country.first<<" : "<<country.second<<endl;
    }//prints in different order
    if(m.count("US")){//count does search operation
        cout<<"US exists\n";
    }else{
        cout<<"US doesnt exists\n";
    }
    m["Nepal"]=20;
    m["Nepal"]=200;//20 will be overwritten
    for(pair<string,int> country : m){
        cout<<country.first<<" : "<<country.second<<endl;
    }//prints in different order

    map<string,val> m;
    m["guru"]=100;
    //all things same as above
    return 0;
}