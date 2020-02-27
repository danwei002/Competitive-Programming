#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, M, T; scanf("%d%d%d", &N, &M, &T);
    vector<int> v[N + 1];
    for (int i = 0; i < M; i++) {
        int a, b; scanf("%d%d", &a, &b);
        v[a].push_back(b);
    }
    
    int dist[N + 1][N + 1];
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= N; j++) {
            dist[i][j] = -1;
        }
    }
    
    for (int i = 1; i <= N; i++) {
        bool vis[N + 1] = {false};
        dist[i][i] = 0; vis[i] = true;
        queue<int> q;
        q.push(i);
        while (!q.empty()) {
            int s = q.front(); q.pop();
            for (auto p: v[s]) {
                if (!vis[p]) {
                    vis[p] = true;
                    dist[i][p] = dist[i][s] + 1;
                    q.push(p);
                }
            }
        }
    }
    
    int Q; scanf("%d", &Q);
    for (int i = 0; i < Q; i++) {
        int a, b; scanf("%d%d", &a, &b);
        int ans = dist[a][b];
        if (ans == -1) {printf("%s\n", "Not enough hallways!");}
        else {printf("%d\n", ans * T);}
    }
    return 0;
}