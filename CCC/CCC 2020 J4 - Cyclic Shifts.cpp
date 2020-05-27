include <bits/stdc++.h>

using namespace std;

int main() {
    string T, S;
    getline(cin, T); getline(cin, S);
    string shift = S.substr(1, S.length() - 1) + S.at(0);
    for (int i = 0; i < S.size(); i++) {
        shift = shift.substr(1, shift.length() - 1) + shift.at(0);
        if (T.find(shift) != string::npos) {cout << "yes\n"; return 0;}
    }

    cout << "no\n";
    return 0;
}