#include <bits/stdc++.h>

using namespace std;

int H, W;
char grid[1001][1001];
int dp[1001][1001];

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> H >> W;
    for (int i = 1; i <= H; i++) {
        for (int j = 1; j <= W; j++) {cin >> grid[i][j];}
    }
    
    for (int i = 1; i <= H; i++) {
        for (int j = 1; j <= W; j++) {
            if (grid[i][j] != '#') {
                if (i == 1 && j == 1) {dp[i][j] = 1;} 
                else if (i == 1 && j != 1) {dp[i][j] = dp[i][j - 1];} 
                else if (i !=  1 && j == 1) {dp[i][j] = dp[i - 1][j];} 
                else {dp[i][j] = dp[i][j - 1] + dp[i - 1][j];}
                dp[i][j] %= 1000000007;
            }
        }
    }
    
    cout << dp[H][W] % 1000000007 << "\n";
    return 0;
}