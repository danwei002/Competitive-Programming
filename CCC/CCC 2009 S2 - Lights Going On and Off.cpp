#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int R, L;
    cin >> R >> L;
    int binary[R][L];
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < L; j++) {
            cin >> binary[i][j];
        }
    }
    
    set<int> ss[R];
    vector<int> dec[R];
    for (int i = 0; i < R; i++) {
        int decVal = 0;
        for (int j = 0; j < L; j++) {
            decVal += binary[i][j] * pow(2, j);
        }
        dec[i].push_back(decVal);
        ss[i].insert(decVal);
    }
    
    for (int i = 0; i < R - 1; i++) {
        int size = dec[i].size();
        int size2 = dec[i + 1].size();
        for (int j = 0; j < size; j++) {
            for (int k = 0; k < size2; k++) {
                dec[i + 1].push_back(dec[i][j] ^ dec[i + 1][k]);
            }
        }
    }
    
    for (auto p: dec[R - 1]) {
        ss[R - 1].insert(p);
    }
    cout << ss[R - 1].size();
}