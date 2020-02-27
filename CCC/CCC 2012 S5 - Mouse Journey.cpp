#include <bits/stdc++.h>

using namespace std;

int main() {
    int R, C, K;
    cin >> R >> C >> K;
    long long int dp[R + 1][C + 1];
    bool hasCat[R + 1][C + 1];
    for (int i = 0; i <= R; i++) {
        for (int j = 0; j <= C; j++) {
            dp[i][j] = 0;
            hasCat[i][j] = false;
        }
    }
    for (int i = 0; i < K; i++) {
        int x, y;
        cin >> x >> y;
        hasCat[x][y] = true;
    }
    dp[1][2] = 1;
    dp[2][1] = 1;
    
    if (hasCat[1][2]) {
        dp[1][2] = 0;
    }
    
    if (hasCat[2][1]) {
        dp[2][1] = 0;
    }
    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            if (!hasCat[i][j]) {
                if (i == 1 && j == 1) {
                    dp[i][j] = 1;   
                } else if (i == 1 && j != 1) {
                    dp[i][j] = dp[i][j - 1];
                } else if (i !=  1 && j == 1) {
                    dp[i][j] = dp[i - 1][j];
                } else {
                    dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
                }
                //cout << "dp[" << i << "]" << "[" << j << "]: " << dp[i][j] << endl; 
            }
        }
    }
    cout << dp[R][C];
}