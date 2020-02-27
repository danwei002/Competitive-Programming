#include <bits/stdc++.h>

using namespace std;

int main() {
    string key, msg, enc;
    getline(cin, key); getline(cin, msg);
    int keys[key.length()];
    for (int i = 0; i < key.length(); i++) {
        keys[i] = (int) key.at(i) - 65;
    }
    
    string nAlpha = "";
    for (int i = 0; i < msg.length(); i++) {
        int ascii = (int) msg.at(i) - 65;
        if (ascii >= 0 and ascii <= 26) {
            char add = (char) ascii + 65;
            nAlpha += add;
        }
    }
    
    int keyInd = 0;
    
    for (int i = 0; i < nAlpha.length(); i++) {
        int c = (int) nAlpha.at(i) - 65;
        int g = c + keys[keyInd] + 65;
        
        if (g > 90) {
            g -= 26;
        }
        
        cout << (char) g;
        keyInd++;
        if (keyInd >= key.length()) {
            keyInd = 0;
        }
    }
}