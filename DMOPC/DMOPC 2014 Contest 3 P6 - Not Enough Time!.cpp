#include <bits/stdc++.h>

using namespace std;

int p[2001][3];
int v[2001][3];
int dp[10001];
int N, T;
int main() {
    memset(dp, -1, sizeof(dp)); dp[0] = 0;
    scanf("%d%d", &N, &T);
    for (int i = 0; i < N; i++) {for (int j = 0; j < 3; j++) {scanf("%d%d", &p[i][j], &v[i][j]);}}
    for (int i = 0; i < N; i++) {
        for (int j = T; j >= 0; j--) {
            for (int k = 0; k < 3; k++) {
                if (dp[j] >= 0 and j + p[i][k] <= T) {
                    dp[j + p[i][k]] = max(dp[j + p[i][k]], dp[j] + v[i][k]);   
                }
            }
        }
    }
    
    int ans = INT_MIN;
    for (int i = 0; i <= T; i++) {ans = max(ans, dp[i]);}
    printf("%d\n", ans);
    return 0;
}