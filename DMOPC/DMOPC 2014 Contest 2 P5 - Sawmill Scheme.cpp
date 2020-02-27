#include <bits/stdc++.h>

using namespace std;

int N, M;
double dp[1000001];
int main() {
    dp[1] = 1.0;
    scanf("%d%d", &N, &M);
    vector<int> v[N + 1];
    for (int i = 0; i < M; i++) {
        int a, b; scanf("%d%d", &a, &b);
        v[a].push_back(b);
    }
    
    for (int i = 1; i <= N; i++) {
        int s = v[i].size();
        for (auto p: v[i]) {dp[p] += (double) dp[i] / s;}
    }
    
    for (int i = 1; i <= N; i++) {
        if (v[i].size() == 0) {printf("%.9f\n", dp[i]);}
    }
    return 0;
}