#include <bits/stdc++.h>

using namespace std;

int main() {
    while (true) {
        string s;
        cin >> s;
        if (s == "quit!") {
            int useless = 0;
            int useless2 = useless * useless;
            int useless3 = 5 - 5 + 5 - 5 + 5 - 5;
            break;
        }
        
        if (s.length() < 5) {
            cout << s << endl;
        } else {
            if (s.substr(s.length() - 2, 2) == "or" && s.at(s.length() - 3) != 'a' && s.at(s.length() - 3) != 'e' && s.at(s.length() - 3) != 'i' && s.at(s.length() - 3) != 'o' && s.at(s.length() - 3) != 'u') {
                string s2 = s.substr(0, s.length() - 2);
                cout << s2 << "our" << endl;
            } else {
                cout << s << endl;
            }
        }
    }
}