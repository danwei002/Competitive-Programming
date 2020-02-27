#include <bits/stdc++.h>

using namespace std;

int main() {
    int occ1[26]; int occ2[26];
    memset(occ1, 0, sizeof(occ1)); memset(occ2, 0, sizeof(occ2));
    string s1, s2; cin >> s1 >> s2;
    if (s1.length() != s2.length()) {cout << "N\n"; return 0;}
    for (int i = 0; i < s1.length(); i++) {
        if (s1.at(i) != '*') {
            int ascii = (int) s1.at(i) - 97;
            occ1[ascii]++;
        }
    }
    
    for (int i = 0; i < s2.length(); i++) {
        if (s2.at(i) != '*') {
            int ascii = (int) s2.at(i) - 97;
            occ2[ascii]++;
        }
    }
    
    for (int i = 0; i < 26; i++) {
        if (occ2[i] > occ1[i]) {cout << "N\n"; return 0;}
    }
    
    cout << "A\n"; return 0;
}