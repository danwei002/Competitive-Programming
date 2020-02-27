#include <bits/stdc++.h>

using namespace std;

int getIndex(string s, string arr[]) {
    for (int i = 0; i < 26; i++) {
        if (arr[i] == s) {
            return i;
            break;
        }
    }
    return -1;
}

int main() {
    int K;
    string encoded;
    string alpha[] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z"};
    
    cin >> K >> encoded;
    
    for (int i = 0; i < encoded.length(); i++) {
        int newK = 3 * (i + 1) + K;
        char character = encoded.at(i);
        string s(1, character);
        int indexOfChar = getIndex(s, alpha);
        int newIndex = indexOfChar - newK;
        
        if (newIndex < 0) {
            newIndex = -newIndex;
            newIndex = 26 - newIndex;
        }
        
        cout << alpha[newIndex];
    }
}