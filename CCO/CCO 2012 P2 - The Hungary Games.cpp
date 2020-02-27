#include <bits/stdc++.h>

using namespace std;

struct Edge {
    long long src, dst, cost;
};

int main() {
    long long N, M;
    scanf("%lld%lld", &N, &M);
    vector<pair<long long, long long>> v[N + 1];
    vector<pair<long long, long long>> v2[N + 1];
    vector<Edge> edges;
    for (int i = 0; i < M; i++) {
        long long A, B, L;
        scanf("%lld%lld%lld", &A, &B, &L);
        v[A].push_back({B, L});
        v2[B].push_back({A, L});
        edges.push_back((Edge) {A, B, L});
    }
    
    bool vis[N + 1] = {false};
    long long dist[N + 1];
    for (int i = 0; i <= N; i++) {dist[i] = LLONG_MAX;}
    dist[1] = 0;
    priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;
    pq.push({dist[1], 1});
    long long u;
    while (!pq.empty()) {
        u = pq.top().second; pq.pop();
        if (vis[u]) {continue;}
        vis[u] = true;
        for (auto p: v[u]) {
            if (dist[p.first] > dist[u] + p.second) {
                dist[p.first] = dist[u] + p.second;
                pq.push({dist[p.first], p.first});
            }
        }
    }
    
    bool vis2[N + 1] = {false};
    int dist2[N + 1];
    for (int i = 0; i <= N; i++) {dist2[i] = INT_MAX;}
    dist2[N] = 0;
    priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq2;
    pq2.push({dist2[N], N});
    long long u2;
    while (!pq2.empty()) {
        u2 = pq2.top().second; pq2.pop();
        if (vis2[u2]) {continue;}
        vis2[u2] = true;
        for (auto p: v2[u2]) {
            if (dist2[p.first] > dist2[u2] + p.second) {
                dist2[p.first] = dist2[u2] + p.second;
                pq2.push({dist2[p.first], p.first});
            }
        }
    }
    
    long long ans = INT_MAX;
    long long shortest = dist[N];
    for (int i = 0; i < edges.size(); i++) {
        Edge &p = edges[i];
        long long s = dist[p.src] + dist2[p.dst] + p.cost;
        if (s > shortest and s < ans) {
            ans = s;
        }
    }
    
    if (ans == INT_MAX) {
        cout << -1 << endl;
        return 0;
    }
    cout << ans;
    return 0;
}