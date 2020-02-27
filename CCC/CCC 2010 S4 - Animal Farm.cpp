#include <bits/stdc++.h>

using namespace std;
int M;
int graph[101][101];
int Prim(int n) {
    int u = 99999999;
    int v[n + 1];
    for (int i = 1; i <= n; i++) {
        v[i] = -u;
    }
    v[0] = -(u + 1);
    int mn = 1;
    int k;
    while (mn != 0) {
        k = mn;
        v[k] *= -1;
        mn = 0;
        if (v[k] == u) {
            v[k] = 0;
        }
        for (int t = 1; t <= n; t++) {
            if (v[t] < 0) {
                if (graph[k - 1][k - 1] != u and v[t] < -graph[k - 1][t - 1]) {
                    v[t] = -graph[k - 1][t - 1];
                }
                if (v[t] > v[mn]) {
                    mn = t;
                }
            }
        }
    }
    int res = 0;
    for (int i = 1; i <= n; i++) {
        res += v[i];
    }
    return res;
}

int main() {
    cin >> M;
    for (int i = 0; i <= M; i++) {
        for (int j = 0; j <= M; j++) {
            if (i == j) {
                graph[i][j] = 0;
            } else {
                graph[i][j] = INT_MAX;
            }
        }
    }
    pair<int, int> input[1001][1001];
    for (int i = 0; i <= 1000; i++) {
        for (int j = 0; j <= 1000; j++) {
            input[i][j] = {-1, 0};
        }
    }
    
    int corner[1001];
    int cost[1001];
    for (int i = 0; i < M; i++) {
        int edges;
        cin >> edges;
        for (int j = 0; j < edges; j++) {
            cin >> corner[j];
        }
        
        for (int j = 0; j < edges; j++) {
            cin >> cost[j];
        }
        
        for (int j = 0; j < edges; j++) {
            int k = (j + 1) % edges;
            if (input[corner[j]][corner[k]].second > 0) {
                if (graph[i][input[corner[j]][corner[k]].first] > cost[j]) {
                    graph[i][input[corner[j]][corner[k]].first] = cost[j];
                    graph[input[corner[j]][corner[k]].first][i] = cost[j];
                }
                input[corner[j]][corner[k]].first = -1;
                input[corner[k]][corner[j]].first = -1;
            } else {
                input[corner[j]][corner[k]].second = cost[j];
                input[corner[j]][corner[k]].first = i;
                input[corner[k]][corner[j]].second = cost[j];
                input[corner[k]][corner[j]].first = i;
            }
        }
    }
    
    for (int i = 0; i <= 1000; i++) {
        for (int j = 0; j <= 1000; j++) {
            if (input[i][j].first >= 0) {
                if (graph[input[i][j].first][M] > input[i][j].second) {
                    graph[input[i][j].first][M] = input[i][j].second;
                    graph[M][input[i][j].first] = input[i][j].second;
                }
            }
        }
    }
    
    cout << min(Prim(M), Prim(M + 1));
}