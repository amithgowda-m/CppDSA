#include <iostream>
#include <cstring>
using namespace std;

void toUpper(char word[],int n){
    for (int i = 0; i < n; i++){
        char ch = word[i];
        if (ch>='A'&&ch<='Z'){
            continue;
        }
        else{
            word[i]=ch-'a'+'A';
        }
    }
}
  
int main(){
    char word[]="ApPle";
    for (int i = 0; i < strlen(word); i++){
        cout<<(char)toupper(word[i]);//Note: To upper returns int so we should convert it to char
    }

    for (int i= 0; i < strlen(word); i++){
        if (word[i]>='a'&& word[i]<='z'){
            cout<<(char)(word[i]-32);
        }
        else{
            cout<<word[i];
        }  
    }
    cout<<"\nby using function\n";
    toUpper(word,strlen(word));
    cout<<word;
    return 0;
}