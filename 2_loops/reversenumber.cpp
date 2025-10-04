#include <iostream>
using namespace std;

int main(){
    int n,lastDig,res=0;
    printf("Enter a number : ");
    scanf("%d",&n);

    // for (int  i = n; i > 0; i--)
    // {
    //     cout<<i<<" ";
    // }
    while (n>0)
    {
        lastDig = n%10;
        res = res*10 + lastDig;   
        n= n/10;
    }
    printf("reversed number is: %d ",res);
    
}











































