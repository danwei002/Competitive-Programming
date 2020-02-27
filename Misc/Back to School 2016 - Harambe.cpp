#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    getline(cin, s);
    int ups = 0; int lows = 0;
    for (int i = 0; i < s.length(); i++) {
        int ascii = (int) s.at(i);
        if (ascii == 32) {
            continue;
        }
        
        if (ascii >= 65 and ascii <= 90) {
            ups++;
        } else {
            lows++;
        }
    }
    
    if (ups == lows) {
        cout << s << endl;
    } else if (ups < lows) {
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        cout << s << endl;
    } else {
        transform(s.begin(), s.end(), s.begin(), ::toupper);
        cout << s << endl;
    }
    return 0;
}