#include <iostream>
#include <cstring>
using namespace std;

int main(){
    char str1[100];
    char str2[100]="Amith";

    // str1="Gowda"; this is impossible
    strcpy(str1,str2);
    cout<<str1<<"\n";

    strcat(str1,str2);
    cout<<"\n"<<str1;

    int cp = strcmp(str1,str2);//compare lexicographically ie according to dicrionary order
    if(cp==0){
        cout<<"\nequal";
    }
    else if(cp <0){
        cout<<"\n1st string is small";
    }
    else{
        cout<<"\n2nd string is small";
    }
    return 0;
}