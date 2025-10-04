#include <iostream>
using namespace std;

int fact(int a){
    if (a==0 || a== 1)
    {
        return 1;
    }
    else{
        return a*fact(a-1);
    }
}

int main(){
    int x = fact(3);
    cout<<x<<endl;
    return 0;
}
