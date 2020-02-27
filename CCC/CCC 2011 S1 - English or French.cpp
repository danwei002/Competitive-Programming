#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    cin.ignore();
    if (N == 0) {
        return 0;
    }
    int tT = 0;
    int sS = 0;
    for (int i = 0; i < N; i++) {
        string s;
        getline(cin, s);
        for (int j = 0; j < s.length(); j++) {
            if (s.at(j) == 'T' or s.at(j) == 't') {
                tT++;
            } else if (s.at(j) == 'S' or s.at(j) == 's') {
                sS++;
            }
        }
    }
    
    if (tT > sS) {
        cout << "English" << endl;
    } else if (tT == sS) {
        cout << "French" << endl;
    } else {
        cout << "French" << endl;
    }
}