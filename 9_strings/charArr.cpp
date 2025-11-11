#include <iostream>
#include <cstring>
using namespace std;
// terminnated by '\0' -> null character

int main(){
    char arr[] = {'a', 'm', 'i', 't', 'h', '\0'}; // char array is always end with null character
    // literal is something whoose value is always same
    char arrl[6] = "amith";
    char name[] = "AmithGowdaM,Next cyber security specialist and hacker";
    // char work[5] = "amith"; // here it give errror because we need extra space to store null character
    char pen[5] = {'a', 'm', 'i', 't', '\0'};
    char male[50]={'a','m','i','t','h'};//
    cout<<"\n"<<strlen(male)<<"\n";
    cout<<"\n"<<male<<"\n";
    cout<<name;
    return 0;
}