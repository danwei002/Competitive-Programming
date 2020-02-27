#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, T;
    scanf("%d", &N); scanf("%d", &T);
    vector<pair<int, int>> g[N + 1];
    for (int i = 0; i < T; i++) {
        int x, y, C;
        scanf("%d", &x); scanf("%d", &y); scanf("%d", &C);
        g[x].push_back(make_pair(y, C));
        g[y].push_back(make_pair(x, C));
    }
    
    int K;
    scanf("%d", &K);
    int sources[K];
    int cost[K];
    for (int i = 0; i < K; i++) {
        int z, P;
        scanf("%d", &z); scanf("%d", &P);
        sources[i] = z;
        cost[i] = P;
    }
    
    int D;
    scanf("%d", &D);
    
    int cur = INT_MAX;
    
    int dist[N + 1];
    for (int k = 0; k <= N; k++) {
        dist[k] = INT_MAX;
    }
    bool vis[N + 1] = {false};
    int v = D;
    dist[v] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({dist[v], v});
    int u;
    while (!pq.empty()) {
        u = pq.top().second; pq.pop();
        if (vis[u]) {
            continue;
        }
        vis[u] = true;
        for (auto p: g[u]) {
            if (dist[p.first] > dist[u] + p.second) {
                dist[p.first] = dist[u] + p.second;
                pq.push({dist[p.first], p.first});
            }
        }
    }
    
    int min = INT_MAX;
    for (int i = 0; i < K; i++) {
        int total = dist[sources[i]] + cost[i];
        if (total < min) {
            min = total;
        }
    }
    cout << min;
}