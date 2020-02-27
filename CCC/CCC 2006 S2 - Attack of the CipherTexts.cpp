#include <bits/stdc++.h>

using namespace std;

int main() {
    string msg;
    getline(cin, msg);
    
    string ciph1;
    getline(cin, ciph1);
    
    string ciph2;
    getline(cin, ciph2);
    
    char alpha[27];
    for (int i = 0; i < 27; i++) {
        alpha[i] = '.';
    }
    for (int i = 0; i < ciph1.length(); i++) {
        char cur = ciph1.at(i);
        if (msg.at(i) == ' ') {
            alpha[26] = cur;
        } else {
            int index = (int) cur - 65;
            alpha[index] = msg.at(i);
        }
    }

    string res = "";
    for (int i = 0; i < ciph2.length(); i++) {
        char c = ciph2.at(i);
        if (c == alpha[26]) {
            res += ' ';
        } else {
            int index = (int) c - 65;
            res += alpha[index];
        }
    }
    cout << res;
}