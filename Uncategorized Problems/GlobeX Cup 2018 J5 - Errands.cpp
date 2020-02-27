#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, M, Q, C;
    scanf("%d%d%d%d", &N, &M, &Q, &C);
    vector<int> v[N + 1];
    for (int i = 0; i < M; i++) {
        int u, z;
        scanf("%d%d", &u, &z);
        v[u].push_back(z);
        v[z].push_back(u);
    }
    
    bool vis[N + 1] = {false};
    int dist[N + 1];
    memset(dist, -1, sizeof(dist));
    queue<int> q;
    dist[C] = 0;
    vis[C] = true;
    q.push(C);
    while (!q.empty()) {
        int s = q.front(); q.pop();
        for (auto p: v[s]) {
            if (!vis[p]) {
                vis[p] = true;
                dist[p] = dist[s] + 1;
                q.push(p);
            }
        }
    }
        
    for (int i = 0; i < Q; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        if (!vis[b] or !vis[a]) {
            cout << "This is a scam!" << endl;
            continue;
        } else {
            cout << dist[a] + dist[b] << endl;
        }
    }
}