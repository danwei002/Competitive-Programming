#include <bits/stdc++.h>

using namespace std;

vector<int> v[10000];
int N, x, y, a, b;
int dist[10000], dist2[10000];
bool vis[10000], vis2[10000];
queue<int> q;

void circle(int src, int dst) {
    memset(dist, -1, sizeof(dist)); memset(vis, 0, sizeof(vis));
    memset(dist2, -1, sizeof(dist2)); memset(vis2, 0, sizeof(vis2));
    dist[src] = 0; vis[src] = 1; q.push(src);
    while (!q.empty()) {
        int s = q.front(); q.pop();
        for (auto p: v[s]) {
            if (!vis[p]) {
                vis[p] = 1;
                dist[p] = dist[s] + 1;
                q.push(p);
            }
        }
    }
    
    if (!vis[dst]) {printf("%s\n", "No"); return;}
    
    vis2[dst] = 1; q.push(dst);
    while (!q.empty()) {
        int s = q.front(); q.pop();
        for (auto p: v[s]) {
            if (p == src) {printf("%s%d\n", "Yes ", dist[dst] - 1); return;}
            if (!vis2[p]) {
                vis2[p] = 1;
                q.push(p);
            }
        }
    }
    printf("%s\n", "No");
    return;
}

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {scanf("%d%d", &x, &y); v[x].push_back(y);}
    scanf("%d%d", &a, &b);
    while (a != 0 and b != 0) {circle(a, b); scanf("%d%d", &a, &b);}
    return 0;
}