#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s[6][6][6];
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            string S;
            cin >> S;
            for (int  k = 0; k < 6; k++) {
                string elem = S.substr(k, 1);
                s[i][j][k] = elem;
            }
        }
    }
    
    int count = 0;
    string win = "RRRR";
    for (int a = 0; a < 6; a++) {
        for (int b = 0; b < 6; b++) {
            for (int c = 0; c < 3; c++) {
                string q = s[a][b][c] + s[a][b][c + 1] + s[a][b][c + 2] + s[a][b][c + 3];
                if (q == win) {
                    count++;
                }
            }
        }
    }
    
    for (int x = 0; x < 6; x++) {
        for (int y = 0; y < 3; y++) {
            for (int z = 0; z < 6; z++) {
                string q2 = s[x][y][z] + s[x][y + 1][z] + s[x][y + 2][z] + s[x][y + 3][z];
                if (q2 == win) {
                    count++;
                }
            }
        }
    }
    
    for (int d = 0; d < 3; d++) {
        for (int e = 0; e < 6; e++) {
            for (int f = 0; f < 6; f++) {
                string q3 = s[d][e][f] + s[d + 1][e][f] + s[d + 2][e][f] + s[d + 3][e][f];
                if (q3 == win) {
                    count++;
                }
            }
        }
    }
    
    if (count != 0) {
        cout << count;
    } else {
        cout << "lost";
    }
}