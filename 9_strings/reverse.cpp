#include <iostream>
#include <cstring>
using namespace std;

void reverse(char arr[],int n){
    int st = 0,en=n-1;
    while (st<en){
        swap(arr[st++],arr[en--]);
    }    
}

int main(){
    char word[]="HTIMA";
    reverse(word,strlen(word));
    cout<<word;
    return 0;
}