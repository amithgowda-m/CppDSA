#include <iostream>
using namespace std;

int main(){
    //all below is explicit typecasting
    const float PI = 3.14;
    cout<< (int(PI))<<endl;
    cout<<(int('A'))<<endl;
    cout<<((float)10/3)<<endl;
    cout<<(char('A'+4))<<endl;

    //implicit typecasting
    cout<<('A'+1 );//In ASCI valur A=65
    return 0;

}