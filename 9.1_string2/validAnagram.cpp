#include <iostream>
using namespace std;

bool isAmagram(string str1, string str2){
    if(str1.length()!=str2.length()){
        cout<<"not valid anagrams";
        return false;
    }
    int count[26]={0};
    for (int i = 0; i < str1.length(); i++){
        int index = str1[i]-'a';
        count[index]++;
    }
    for (int i = 0; i < str2.length(); i++){
        int index = str2[i]-'a';
        if(count[index]==0){
            cout<<"Not valid angrams";
            return false;
        }
        else{
            count[index]--;
        }
    }
    cout<<"valid anagrams";
    return true;
}


int main(){
    string str1 = "cat";
    string str2 = "dog";
    isAmagram(str1,str2);
    return 0;
}