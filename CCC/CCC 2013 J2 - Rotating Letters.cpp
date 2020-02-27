#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    bool ok = true;
    
    for (int i = 0; i < s.length(); i++) {
        if (s.substr(i, 1) == "I" || s.substr(i, 1) == "O" || s.substr(i, 1) == "S" || s.substr(i, 1) == "X" || s.substr(i, 1) == "H" || s.substr(i, 1) == "N" || s.substr(i, 1) == "Z") {
            ok = true;
        } else {
            ok = false;
        }
    }
    
    if (ok) {
        cout << "YES";
    } else {
        cout << "NO";
    }
}