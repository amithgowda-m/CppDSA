#include <iostream>
// #include <ctype.h>
#include <cstring>
using namespace std;

int main(){
    char word[30];
    cin>>word;//as soon as i enter a space it will ignore next words
    cout<<"Your word was : "<<word<<endl;
    cout<<"length: "<<strlen(word)<<endl;
    //so for that sake we can use cin.getline()
    char sentence[50];
    cout<<"Enter your sentence : "<<endl;
    cin.getline(sentence,50,'.');//this arguement is optional it is calledd delimitter
    cout<<"Your sentence was : "<<sentence;
    return 0;
}

// Notice input stops at . because we set it as the delimiter.
// If you omit the third argument, it defaults to newline \n.