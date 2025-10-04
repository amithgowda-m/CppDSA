#include <iostream>
#include <string>
using namespace std;

void binString(int n, int lastPlace, string ans){
    if(n==0){
        cout<<ans<<endl;
        return;
    }

    if (lastPlace!=1){
        binString(n-1,0,ans+'0');//Append a 0 to the answer, decrease n by 1, and say the last bit was 0.
        binString(n-1,1,ans+'1');//Append a 1 to the answer, decrease n by 1, and say the last bit was 1.
    }
    else{
        binString(n-1,0,ans+'0');//If the last bit was 1, then you cannot place another 1 (because you don’t want consecutive 1s).So you only recurse with a 0.
    }
}

void binStringl(int n, string ans){
    if(n==0){
        cout<<ans<<endl;
        return;
    }

    if ((ans.size()-1)!=1){//here we should not check for ==0{
        binStringl(n-1,ans+'0');//Append a 0 to the answer, decrease n by 1, and say the last bit was 0.
        binStringl(n-1,ans+'1');//Append a 1 to the answer, decrease n by 1, and say the last bit was 1.
    }
    else{
        binStringl(n-1,ans+'0');//If the last bit was 1, then you cannot place another 1 (because you don’t want consecutive 1s).So you only recurse with a 0.
    }
}

int main(){
    string ans ="";
    binString(3,0,ans);//we want binary strings of length 3, and we act like the “last placed” bit was 0 (so we’re free to put either 0 or 1 first).
    return 0;
}