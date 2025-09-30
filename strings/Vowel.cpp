#include <iostream>
#include <cstring>
using namespace std;

int main(){
    char word[100];
    cout<<"Enter a string ";
    cin.getline(word, 100);
    int count =0;
    for (int i = 0; word[i] !='\0'; i++)
    {
        char ch =word[i];
        word[i]=tolower(word[i]);
        if (word[i]=='a'||word[i]=='e'||word[i]=='i'||word[i]=='o'||word[i]=='u')
        {
            count++;
        }
        
    }
    cout<<count;
}