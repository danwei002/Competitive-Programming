#include <bits/stdc++.h>

using namespace std;

int main() {
    int t, s, h;
    cin >> t >> s >> h;
    for (int i = 0; i < t; i++) {
        for (int j = 0; j < 3; j++) {
            cout << "*";
            for (int k = 0; k < s; k++) {
                cout << " ";
            }
        }
        cout << endl;
    }
    
    for (int i = 0; i < 3 + 2 * s; i++) {
        cout << "*";
    }
    cout << endl;
    
    for (int i = 0; i < h; i++) {
        for (int j = 0; j <= s; j++) {
            cout << " ";
        }
        cout << "*" << endl;
    }
}