#include <iostream>
#include <cstring>
using namespace std;

bool check(char word[], int n) {
    int len = strlen(word) - 1; // index of last character
    while (n < len) {
        if (word[n] != word[len]) {
            return false;
        }
        n++;
        len--;
    }
    return true;
}

int main() {
    char word[] = "sees";
    int startIndex = 0;
    if (check(word, startIndex)) {
        cout << "Palindrome" << endl;
    } else {
        cout << "Not a palindrome" << endl;
    }
    char work[]="bees";
    strcpy(word,work);
    cout<<"\n"<<word;
    return 0;
}
