//count total ways to tile a floow (2*n) with tiles (2*1)

#include <iostream>
#include <string>
using namespace std;


int tileProblem(int n){ //2*n
    if (n==0||n==1){///base class
        return 1;
    }
    
    //vertical
    int ans1 = tileProblem(n-1);

    //horizantal
    int ans2 = tileProblem(n-2);

    return ans1+ans2;
}

int main(){
    int n=4;
    cout<<tileProblem(n)<<endl;
    return 0;
}

