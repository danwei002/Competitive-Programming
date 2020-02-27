#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, M; scanf("%d%d", &N, &M);
    vector<pair<int, int>> v[N];
    for (int i = 0; i < M; i++) {
        int a, b, t; scanf("%d%d%d", &a, &b, &t);
        v[a].push_back({b, t}); v[b].push_back({a, t});
    }
    
    int dist[N]; bool vis[N];
    memset(dist, 1000000, sizeof(dist)); memset(vis, false, sizeof(vis));
    dist[0] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({dist[0], 0});
    while (!pq.empty()) {
        int u = pq.top().second; pq.pop();
        if (vis[u]) {continue;}
        vis[u] = true;
        for (auto p: v[u]) {
            if (dist[p.first] > dist[u] + p.second) {
                dist[p.first] = dist[u] + p.second;
                pq.push({dist[p.first], p.first});
            }
        }
    }
    
    int dist2[N]; bool vis2[N];
    memset(dist2, 1000000, sizeof(dist2)); memset(vis2, false, sizeof(vis2));
    dist2[N - 1] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq2;
    pq2.push({dist2[N - 1], N - 1});
    while (!pq2.empty()) {
        int u = pq2.top().second; pq2.pop();
        if (vis2[u]) {continue;}
        vis2[u] = true;
        for (auto p: v[u]) {
            if (dist2[p.first] > dist2[u] + p.second) {
                dist2[p.first] = dist2[u] + p.second;
                pq2.push({dist2[p.first], p.first});
            }
        }
    }
    
    int mx = INT_MIN;
    for (int i = 0; i < N; i++) {
        if (dist[i] != 1000000 and dist2[i] != 1000000) {
            mx = max(mx, dist[i] + dist2[i]);
        }
    }
    printf("%d\n", mx);
    return 0;
}