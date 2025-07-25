#include <iostream>
using namespace std;

void insertionSort(char arr[],int n){
    for (int i = 0; i < n; i++){
        int curr = arr[i];
        int prev =i-1;

        while (prev>=0 && arr[prev]>curr)
        {
            arr[prev+1]=arr[prev];
            prev--;
        }
        arr[prev+1]=curr;
        
    }
}
int main(){
    char ch[]={'f','b','a','e','c','d'};
    int n = sizeof(ch)/sizeof(char);

    insertionSort(ch,n);
    for (int i = 0; i < n; i++)
    {
        cout<<ch[i];
    }
    cout<<(int)ch[0];
}