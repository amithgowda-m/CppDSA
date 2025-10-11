#include <iostream>
#include <vector>
using namespace std;

void permutation(string str, string ans){
    if (str.size() == 0) {
    cout << ans << endl;
    return;
    }

    int n  = str.size();
    for (int i = 0; i < str.size(); i++){
        char ch = str[i];
    //    "abcdefgh",i=2=> "ab"+"defgh" => 
        string nextStr = str.substr(0,i)+str.substr(i+1,n-i-1);
        permutation(nextStr,ans+ch);
    } 
}

int main(){
    string str = "abc";
    string ans ="";
    
    permutation(str,ans);
    return 0;
}