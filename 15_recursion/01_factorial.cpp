#include <iostream>
using namespace std;

int fact(int x){
    if(x == 1 || x == 0){  // Use logical OR here
        return 1;// i used bitwise before so
    }
    else{
        return x * fact(x - 1);
    }
}

int main(){
    int n = 0;
    cout<<"Enter a number to get its factorial  ";
    cin>>n;
    int res = fact(n);
    cout <<"Factorial of "<<n<<" is " << res;  // Output: 120
    return 0;
}
