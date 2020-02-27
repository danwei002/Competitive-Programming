#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef pair<int, pii> pipii;

pii p[2001];
vector<pipii> v;
int dp[2001], pr[2001], dist[2001];
int N;
int main() {
    scanf("%d", &N); p[0] = {0, 0};
    for (int i = 1; i <= N; i++) {
        int x, y; scanf("%d%d", &x, &y); p[i] = {x, y};
        for (int j = 0; j < i; j++) {
            int a = p[i].first - p[j].first; int b = p[i].second - p[j].second;
            v.push_back({a * a + b * b, {j, i}});
        }
    }
    sort(v.begin(), v.end(), less<pipii>());
    for (int i = 0; i < v.size(); i++) {
        int s = v[i].second.first; int t = v[i].second.second; int u = v[i].first;
        if (u != dist[s]) {dist[s] = u; pr[s] = dp[s];}
        if (u != dist[t]) {dist[t] = u; pr[t] = dp[t];}
        if (s == 0) {dp[s] = max(dp[s], pr[t]);}
        else {dp[s] = max(dp[s], pr[t] + 1); dp[t] = max(dp[t], pr[s] + 1);}
    }
    printf("%d\n", dp[0] + 1);
    return 0;
}