#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

ll N, M, D;
vector<pll> v[500001];
vector<pll> v2[500001];
pair<ll, pll> c[500001];
ll dist[500001], dist2[500001];
bool vis[500001], vis2[500001];

int main() {
    scanf("%lld%lld", &N, &M);
    for (int i = 0; i <= N; i++) {dist[i] = INT_MAX; dist2[i] = INT_MAX; vis[i] = false; vis2[i] = false;}
    for (int i = 0; i < M; i++) {
        ll a, b, t; scanf("%lld%lld%lld", &a, &b, &t);
        v[a].push_back({b, t}); v2[b].push_back({a, t});
    }
    
    scanf("%lld", &D);
    for (int i = 0; i < D; i++) {
        ll a, b, k; scanf("%lld%lld%lld", &a, &b, &k);
        c[i] = {a, {b, k}};
    }
    
    dist[1] = 0;
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    pq.push({dist[1], 1});
    while (!pq.empty()) {
        ll u = pq.top().second; pq.pop();
        if (vis[u]) {continue;}
        vis[u] = true;
        for (auto p: v[u]) {
            if (dist[p.first] > dist[u] + p.second) {
                dist[p.first] = dist[u] + p.second;
                pq.push({dist[p.first], p.first});
            }
        }
    }
    
    dist2[N] = 0;
    pq.push({dist2[N], N});
    while (!pq.empty()) {
        ll u = pq.top().second; pq.pop();
        if (vis2[u]) {continue;}
        vis2[u] = true;
        for (auto p: v2[u]) {
            if (dist2[p.first] > dist2[u] + p.second) {
                dist2[p.first] = dist2[u] + p.second;
                pq.push({dist2[p.first], p.first});
            }
        }
    }
    
    ll ans = dist[N];
    for (int i = 0; i < D; i++) {ans = min(ans, dist[c[i].first] + c[i].second.second + dist2[c[i].second.first]);}
    if (ans == INT_MAX) {printf("%d\n", -1); return 0;}
    printf("%lld\n", ans);
    return 0;
}#include <bits/stdc++.h>

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