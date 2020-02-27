#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, M;
    scanf("%d%d", &N, &M);
    vector<pair<long long, pair<long long, long long>>> v[N + 1];
    for (long long i = 1; i <= M; i++) {
        long long a, b, c;
        scanf("%lld%lld%lld", &a, &b, &c);
        v[a].push_back({b, {c, i}});
        v[b].push_back({a, {c, i}});
    }
    
    long long A, B, C;
    scanf("%lld%lld%lld", &A, &B, &C);
    
    long long lo = 1; long long hi = M;
    long long pass = -1;
    while (lo <= hi) {
        long long mid = (lo + hi) / 2;
        priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;
        bool vis[N + 1];
        long long dist[N + 1];
        for (int i = 0; i <= N; i++) {vis[i] = false; dist[i] = INT_MAX;}
        dist[A] = 0;
        pq.push({dist[A], A});
        while (!pq.empty()) {
            long long u = pq.top().second; pq.pop();
            if (vis[u]) {continue;}
            vis[u] = true;
            for (auto p: v[u]) {
                long long order = p.second.second;
                if (order <= mid) {
                    if (dist[p.first] > dist[u] + p.second.first) {
                        dist[p.first] = dist[u] + p.second.first;
                        pq.push({dist[p.first], p.first});
                    }
                }
            }
        }
        
        if (vis[B]) {
            if (dist[B] <= C) { pass = mid; hi = mid - 1;}
            else {lo = mid + 1;}
        } else {lo = mid + 1;}
    }
    printf("%lld\n", pass);
    return 0;
}