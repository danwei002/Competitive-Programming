#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, M;
    scanf("%d", &N); scanf("%d", &M);
    vector<pair<int, int>> g[N + 1];
    for (int i = 0; i < M; i++) {
        int u, v, w;
        scanf("%d", &u); scanf("%d", &v); scanf("%d", &w);
        g[u].push_back(make_pair(v, w));
        g[v].push_back(make_pair(u, w));
    }
    
    int dist[N + 1];
    for (int k = 0; k <= N; k++) {
        dist[k] = INT_MAX;
    }
    
    bool vis[N + 1] = {false};
    int v = 1;
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
    
    for (int i = 1; i <= N; i++) {
        if (dist[i] == INT_MAX) {
            cout << -1 << endl;
        } else {
            cout << dist[i] << endl;
        }
    }
}