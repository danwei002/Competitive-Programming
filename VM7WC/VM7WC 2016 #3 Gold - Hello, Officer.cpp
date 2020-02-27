#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, M, B, Q;
    scanf("%d%d%d%d", &N, &M, &B, &Q);
    vector<pair<int, int>> v[N + 1];
    for (int i = 0; i < M; i++) {
        int X, Y, Z;
        scanf("%d%d%d", &X, &Y, &Z);
        v[X].push_back({Y, Z});
        v[Y].push_back({X, Z});
    }
    
    bool vis[N + 1];
    int dist[N + 1];
    for (int i = 0; i <= N; i++) {vis[i] = false; dist[i] = INT_MAX;}
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[B] = 0;
    pq.push({dist[B], B});
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
    
    for (int i = 0; i < Q; i++) {
        int A;
        scanf("%d", &A);
        if (dist[A] == INT_MAX) {printf("%d\n", -1);}
        else {printf("%d\n", dist[A]);}
    }
    return 0;
}