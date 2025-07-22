#include <iostream>
using namespace std;

int main(){
    int *ptr = NULL;
    // cout<<*ptr;//if dereferened we get segmentation fault next wont get executed
    cout<<ptr;
}
