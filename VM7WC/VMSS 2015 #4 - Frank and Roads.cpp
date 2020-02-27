#include <bits/stdc++.h>

using namespace std;

int main() {
    int T, N, M, G; scanf("%d%d%d%d", &T, &N, &M, &G);
    int basic[G];
    for (int i = 0; i < G; i++) {scanf("%d", &basic[i]);}
    
    vector<pair<int, int>> v[N + 1];
    for (int i = 0; i < M; i++) {
        int A, B, L;
        scanf("%d%d%d", &A, &B, &L);
        v[A].push_back({B, L});
    }
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    bool vis[N + 1]; int dist[N + 1];
    for (int i = 0; i <= N; i++) {vis[i] = false; dist[i] = INT_MAX;}
    dist[0] = 0;
    pq.push({dist[0], 0});
    int u;
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
    
    int can = 0;
    for (auto q: basic) {
        if (vis[q] and dist[q] <= T) {can++;}
    }
    
    printf("%d\n", can);
    return 0;
}