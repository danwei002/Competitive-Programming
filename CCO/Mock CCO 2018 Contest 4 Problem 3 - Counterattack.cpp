#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

struct Edge {ll src, dst, cost;};

int main() {
    ll N, M;
    scanf("%lld%lld", &N, &M);
    vector<pll> v[N + 1];
    vector<Edge*> edges;
    for (int i = 0; i < M; i++) {
        ll A, B, L;
        scanf("%lld%lld%lld", &A, &B, &L);
        v[A].push_back({B, L});
        v[B].push_back({A, L});
        Edge *e = new Edge();
        e -> src = A; e -> dst = B; e -> cost = L;
        edges.push_back(e);
        Edge *f = new Edge();
        f -> src = B; f -> dst = A; f -> cost = L;
        edges.push_back(f);
    }
    
    bool vis[N + 1]; memset(vis, 0, sizeof(vis)); 
    ll dist[N + 1]; memset(dist, 0x3f3f3f3f, sizeof(dist));
    for (int i = 0; i <= N; i++) {dist[i] = INT_MAX;}
    dist[1] = 0; vis[1] = 1;
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    pq.push({dist[1], 1});
    ll u;
    while (!pq.empty()) {
        u = pq.top().second; pq.pop();
        vis[u] = 0;
        for (auto p: v[u]) {
            if (dist[p.first] > dist[u] + p.second) {
                dist[p.first] = dist[u] + p.second;
                if (!vis[p.first]) {
                    pq.push({dist[p.first], p.first});
                    vis[p.first] = 1;
                }
            }
        }
    }
    
    bool vis2[N + 1]; memset(vis2, 0, sizeof(vis2));
    ll dist2[N + 1]; memset(dist2, 0x3f3f3f3f, sizeof(dist2));
    for (int i = 0; i <= N; i++) {dist2[i] = INT_MAX;}
    dist2[N] = 0; vis2[N] = 1;
    pq.push({dist2[N], N});
    ll u2;
    while (!pq.empty()) {
        u2 = pq.top().second; pq.pop();
        vis2[u2] = 0;
        for (auto p: v[u2]) {
            if (dist2[p.first] > dist2[u2] + p.second) {
                dist2[p.first] = dist2[u2] + p.second;
                if(!vis2[p.first]) {
                    pq.push({dist2[p.first], p.first});
                    vis2[p.first] = 1;
                }
            }
        }
    }
    
    ll ans = 0x3f3f3f3f;
    ll shortest = dist[N];
    for (int i = 0; i < edges.size(); i++) {
        Edge *p = edges[i];
        ll s = dist[p -> src] + dist2[p -> dst] + p -> cost;
        if (ans > s and shortest < s) {ans = s;}
    }
    
    if (ans == 0x3f3f3f3f) {printf("%d\n", -1); return 0;}
    printf("%lld\n", ans);
    return 0;
}