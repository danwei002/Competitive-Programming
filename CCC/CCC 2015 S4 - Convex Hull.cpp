#include <bits/stdc++.h>

using namespace std;

int main() {
    int K, N, M;
    cin >> K >> N >> M;
    vector<pair<long long, long long>> islands[N + 1];
    vector<pair<long long, long long>> wear[N + 1];
    for (int i = 0; i < M; i++) {
        long long a, b, t, h;
        cin >> a >> b >> t >> h;
        islands[a].push_back({b, t});
        islands[b].push_back({a, t});
        wear[a].push_back({b, h});
        wear[b].push_back({a, h});
    }
    
    long long A, B;
    cin >> A >> B;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    long long dist[N + 1][201];
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= 200; j++) {
            dist[i][j] = 1000000000000;
        }
    }
    dist[A][0] = 0;
    bool vis[N + 1];
    memset(vis, false, sizeof(vis));
    vis[A] = true;
    pq.push({0, A});
    while (!pq.empty()) {
        long long u = pq.top().second;
        vis[u] = false;
        pq.pop();
        for (int i = 0; i < islands[u].size(); i++) {
            for (int j = 0; j + wear[u][i].second < K; j++) {
                long long s = dist[u][j] + islands[u][i].second;
                if (s < dist[islands[u][i].first][j + wear[u][i].second]) {
                    dist[islands[u][i].first][j + wear[u][i].second] = s;
                    if (!vis[islands[u][i].first]) {
                        vis[islands[u][i].first] = true;
                        pq.push({s, islands[u][i].first});
                    }
                }
            }
        }
    }
    
    long long mn = INT_MAX;
    for (int i = 0; i < K; i++) {
        mn = min(mn, dist[B][i]);
    }
    if (mn == INT_MAX) {
        cout << -1 << endl;
    } else {
        cout << mn << endl;
    }
}