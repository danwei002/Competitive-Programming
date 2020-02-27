#include <bits/stdc++.h>

using namespace std;

int M, U, R;
int dp[301][101];
int main() {
    scanf("%d%d%d", &M, &U, &R);
    for (int i = 0; i < R; i++) {
        int V, T, F; scanf("%d%d%d", &V, &T, &F);
        for (int j = M; j >= T; j--) {
            for (int k = U; k >= F; k--) {dp[j][k] = max(dp[j][k], V + dp[j - T][k - F]);}
        }
    }
    printf("%d\n", dp[M][U]);
    return 0;
}