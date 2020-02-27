#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, W;
    cin >> N >> W;
    long long values[N];
    int weights[N];
    long long dp[W + 1];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < N; i++) {
        cin >> weights[i] >> values[i];
    }
    
    for (int i = 0; i < N; i++) {
        for (int j = W; j >= weights[i]; j--) {
            dp[j] = max(dp[j], dp[j - weights[i]] + values[i]);
        }
    }

    cout << dp[W] << endl;
    return 0;
}