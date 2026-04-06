#include <iostream>
#include <algorithm>
#include <vector>
#include<math.h>
using namespace std;

int main(){
    vector <int> A={4,1,8,7};
    vector <int> B={2,3,6,5};

    sort(A.begin(),A.end());
    sort(B.begin(),B.end());//O(nlogn)

    int absDif=0;
    for(int i=0;i<A.size();i++){
        absDif+=abs(A[i]-B[i]);

    }
    cout<<"Min absolute differnece : "<<absDif;
    return 0;
}
