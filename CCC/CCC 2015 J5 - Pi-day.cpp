#include <bits/stdc++.h>

using namespace std;

int dp[300][300][300];
long long n, k;
long long combo(long long n, long long k, long long min) {
    if (k * min == n) {
        return 1;
    }
    
    if (k == 1) {
        return 1;
    }
    
    if (dp[n][k][min] != -1) {
        return dp[n][k][min];
    }
    
    long long int s = 0;
    for (int i = min; i <= n / k; i++) {
        s += combo(n - i, k - 1, i);
    }
    return dp[n][k][min] = s;
}

int main() {
    cin >> n >> k;
    memset(dp, -1, sizeof(dp));
    if (n == k) {
        cout << 1;
    } else if (k == 1) {
        cout << 1;
    } else {
        cout << combo(n, k, 1);
    }
}