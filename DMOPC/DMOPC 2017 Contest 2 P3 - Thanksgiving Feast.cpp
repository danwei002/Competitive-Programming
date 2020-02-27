#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, M, K, A, B; scanf("%d%d%d%d%d", &N, &M, &K, &A, &B);
    int gift[K];
    for (int i = 0; i < K; i++) {scanf("%d", &gift[i]);}
    vector<int> v[N + 1];
    for (int i = 0; i < M; i++) {
        int a, b; scanf("%d%d", &a, &b);
        v[a].push_back(b); v[b].push_back(a);
    }
    
    bool vis[N + 1] = {false};
    int dist[N + 1]; memset(dist, -1, sizeof(dist));
    vis[A] = true; dist[A] = 0;
    queue<int> q; q.push(A);
    while (!q.empty()) {
        int s = q.front(); q.pop();
        for (auto p: v[s]) {
            if (!vis[p]) {
                vis[p] = true; dist[p] = dist[s] + 1;
                q.push(p);
            }
        }
    }
    
    bool vis2[N + 1] = {false};
    int dist2[N + 1]; memset(dist2, -1, sizeof(dist2));
    vis2[A] = true; dist2[B] = 0;
    queue<int> q2; q2.push(B);
    while (!q2.empty()) {
        int s = q2.front(); q2.pop();
        for (auto p: v[s]) {
            if (!vis2[p]) {
                vis2[p] = true; dist2[p] = dist2[s] + 1;
                q2.push(p);
            }
        }
    }
    
    int mn = INT_MAX;
    for (int i = 0; i < K; i++) {
        if (dist[gift[i]] != -1 and dist2[gift[i]] != -1) {
            mn = min(mn, dist[gift[i]] + dist2[gift[i]]);
        }
    }
    printf("%d\n", mn);
    return 0;
}