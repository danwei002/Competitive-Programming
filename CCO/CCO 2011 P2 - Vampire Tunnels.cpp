#include <bits/stdc++.h>

using namespace std;

int main() {
    int S, N, E; scanf("%d%d%d", &S, &N, &E);
    vector<pair<int, int>> v[N];
    vector<pair<int, int>> w[N];
    
    for (int i = 0; i < E; i++) {
        int s, t, d, u; scanf("%d%d%d%d", &s, &t, &d, &u);
        v[s].push_back({t, d});
        v[t].push_back({s, d});
        w[s].push_back({t, u * d});
        w[t].push_back({s, u * d});
    }
    
    bool vis[N] = {false}; 
    int dist[N][3601];
    for (int i = 0; i < N; i++) {for (int j = 0; j <= 3600; j++) {dist[i][j] = 1000000;}}
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vis[0] = true; dist[0][0] = 0;
    pq.push({0, 0});
    while (!pq.empty()) {
        int u = pq.top().second;
        vis[u] = false;
        pq.pop();
        for (int i = 0; i < v[u].size(); i++) {
            for (int j = 0; j + w[u][i].second <= S; j++) {
                int s = dist[u][j] + v[u][i].second;
                if (s < dist[v[u][i].first][j + w[u][i].second]) {
                    dist[v[u][i].first][j + w[u][i].second] = s;
                    if (!vis[v[u][i].first]) {
                        vis[v[u][i].first] = true; 
                        pq.push({s, v[u][i].first});
                    }
                }
            }
        }
    }
    
    int mn = 1000000;
    for (int i = 0; i <= S; i++) {mn = min(mn, dist[N - 1][i]);}
    if (mn == 1000000) {printf("%d\n", -1);}
    else {printf("%d\n", mn);}
    return 0;
}