#include <iostream>
#include <string>
using namespace std;

void removeDuplicate(string str, string ans,int i, bool map[]){
    if(i==str.size()){
        cout<<" ans : "<<ans<<endl;
        return;
    }
    char ch = str[i];
    int mapIdx = (int)(ch - 'a'); //to get index
    
    if (map[mapIdx]){//duplicate character
        removeDuplicate(str,ans,i+1,map);
    }
    else{
        map[mapIdx] = true;
        removeDuplicate(str,ans+str[i],i+1,map);
    }
}

void remDupI(string str, string ans, bool map[]){
    if(str.size() ==0){
        cout<<"ans : "<<ans<<endl;
        return;
    }
    int n = str.size();
    char ch = str[n-1];
    int mapInd = (int)(str[n-1]-'a');
    str = str.substr(0,n-1);

    if (map[mapInd]){
        remDupI(str, ans,map);//Each recursive call chops off one character from the end (str = str.substr(0,n-1)) 
    }
    else{
        map[mapInd]=true;
        remDupI(str,ans+ch,map);
    }
}

int main(){
    bool map[26]={0};//we can also write false in the place of 0
    string str = "amithgowdam";
    string ans="";
    removeDuplicate(str,ans,0,map);
    remDupI(str,ans,map);
    return 0;
}