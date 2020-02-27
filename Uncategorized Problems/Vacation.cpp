#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    scanf("%d", &N);
    int dp[N + 1][3];
    int activities[N + 1][3];
    for (int i = 0; i <= N; i++) {dp[i][0] = 0; dp[i][1] = 0; dp[i][2] = 0;}
    for (int i = 1; i <= N; i++) {scanf("%d", &activities[i][0]); scanf("%d", &activities[i][1]); scanf("%d", &activities[i][2]);}
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                if (k != j) {dp[i][k] = max(dp[i][k], dp[i - 1][j] + activities[i][k]);}
            }
        }
    }
   
    printf("%d\n", max(dp[N][0], max(dp[N][1], dp[N][2])));
    return 0;
}