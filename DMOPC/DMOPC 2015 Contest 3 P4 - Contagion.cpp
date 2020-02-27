#include <bits/stdc++.h>

using namespace std;

int main() {
    long long N; scanf("%lld", &N);
    long long coordsX[N + 1]; 
    long long coordsY[N + 1];
    memset(coordsX, 0, sizeof(coordsX)); 
    memset(coordsY, 0, sizeof(coordsY));
    for (long long i = 1LL; i <= N; i++) {scanf("%lld%lld", &coordsX[i], &coordsY[i]);}
    long long X; scanf("%lld", &X);
    vector<long long> v[N + 1];
    for (long long i = 1LL; i <= N; i++) {
        for (long long j = 1LL; j <= N; j++) {
            if (i != j) {
                v[i].push_back(j);
            }
        }
    }
    
    bool vis[N + 1]; 
    long long dist[N + 1];
    memset(vis, false, sizeof(vis)); memset(dist, 0x3f3f3f3f3f3f3f3f, sizeof(dist));
    dist[X] = 0;
    long long u;
    while (true) {
        long long x = 0x3f3f3f3f3f3f3f3f;
        u = -1;
        for (long long i = 1; i <= N; i++) {
            if (!vis[i] and x >= dist[i]) {
                x = dist[i]; u = i;
            }
        }
        if (u == -1) {break;}
        vis[u] = true;
        for (auto p: v[u]) {
            long long dX = abs(coordsX[u] - coordsX[p]); long long dY = abs(coordsY[u] - coordsY[p]);
            long long alt = (dX * dX) + (dY * dY);
            if (dist[p] > dist[u] + alt) {
                dist[p] = dist[u] + alt;
            }
        }
    }
    
    long long Q; scanf("%lld", &Q);
    int n = sizeof(dist) / sizeof(dist[0]); sort(dist, dist + n);
    for (long long i = 0LL; i < Q; i++) {
        long long qi; scanf("%lld", &qi);
        long long lo = 0; long long hi = N; long long mid = (lo + hi) / 2;
        while (lo <= hi) {
            if (dist[mid] <= qi) {lo = mid + 1;}
            else {hi = mid - 1;}
            mid = (lo + hi) / 2;
        }
        printf("%lld\n", mid + 1);
    }
}