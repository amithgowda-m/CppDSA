#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int MAX_CHAR = 256;

void shiftTableGeneration(string pattern, vector<int>& table) {
    int m = pattern.length();
    for (int i = 0; i < MAX_CHAR; i++) table[i] = m;
    for (int i = 0; i < m - 1; i++) {
        table[(int)pattern[i]] = m - 1 - i;
    }
}

int horspoolSearch(string text, string pattern) {
    int n = text.length();
    int m = pattern.length();
    vector<int> table(MAX_CHAR);
    
    shiftTableGeneration(pattern, table);
    
    int i = m - 1; // Position of the pattern pointer in text
    while (i < n) {
        int k = 0;
        while (k < m && pattern[m - 1 - k] == text[i - k]) {
            k++;
        }
        if (k == m) return i - m + 1; // Match found (returns index)
        else i += table[(int)text[i]]; // Shift
    }
    return -1; // Match not found
}

int main() {
    string text = "BARD_LOVES_BANANAS";
    string pattern = "BANANA";
    int index = horspoolSearch(text, pattern);
    if (index != -1) cout << "Pattern found at index: " << index << endl;
    else cout << "Pattern not found" << endl;
    return 0;
}