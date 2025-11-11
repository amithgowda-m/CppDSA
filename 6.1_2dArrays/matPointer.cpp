#include <iostream>
using namespace std;

int main(){
    int arr[5][5] = {{1, 2, 3, 4, 5},
                     {6, 7, 8, 9, 10}, 
                     {11, 12, 13, 14, 15}, 
                     {16, 17, 18, 19, 20}, 
                     {21, 22, 23, 24, 25}};
    

    cout<<arr<<" "<<&arr[0][0]<<"\n";
    cout<<arr+1<<" "<<&arr[0][1]<<"\n";
    cout<<arr+1<<" "<<&arr[1][0]<<"\n";
    cout<<*(*(arr)+1)<<endl;
    cout<<*(*(arr+1)+1);
}