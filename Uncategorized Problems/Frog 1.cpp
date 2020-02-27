#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    int stones[N + 1];
    int DP[N + 1];
    for (int i = 1; i <= N; i++) {
        cin >> stones[i];
        DP[i] = INT_MAX;
    }
    
    if (N == 2) {
        cout << abs(stones[2] - stones[1]);
    } else {
        DP[1] = 0;
        for (int i = 1; i <= N - 2; i++) {
            DP[i + 1] = min(DP[i] + abs(stones[i] - stones[i + 1]), DP[i + 1]);
            DP[i + 2] = min(DP[i] + abs(stones[i] - stones[i + 2]), DP[i + 2]);
        }
        DP[N] = min(DP[N - 2] + abs(stones[N] - stones[N - 2]), DP[N - 1] + abs(stones[N] - stones[N - 1]));
        cout << DP[N];
    }
}