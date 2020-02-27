#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    char city[n][m];
    int startR, startC, endR, endC;
    int dist[n][m];
    bool vis[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> city[i][j];
            if (city[i][j] == 's') {
                startR = i;
                startC = j;
            } else if (city[i][j] == 'e') {
                endR = i;
                endC = j;
            }
            dist[i][j] = -1;
            vis[i][j] = false;
        }
    }
    
    queue<pair<int, int>> q;
    q.push({startR, startC});
    dist[startR][startC] = 0;
    vis[startR][startC] = true;
    while (!q.empty()) {
        startR = q.front().first; startC = q.front().second; q.pop();
        int r1, r2, c1, c2;
        r1 = startR - 1; r2 = startR + 1; c1 = startC - 1; c2 = startC + 1;
        if (r1 >= 0) {
            if (city[r1][startC] != 'X' && !vis[r1][startC]) {
                vis[r1][startC] = true;
                dist[r1][startC] = dist[startR][startC] + 1;
                q.push({r1, startC});
            }
        }
            
        if (r2 < n) {
            if (city[r2][startC] != 'X' && !vis[r2][startC]) {
                vis[r2][startC] = true;
                dist[r2][startC] = dist[startR][startC] + 1;
                q.push({r2, startC});
            }
        }
        
        if (c1 >= 0) {
            if (city[startR][c1] != 'X' && !vis[startR][c1]) {
                vis[startR][c1] = true;
                dist[startR][c1] = dist[startR][startC] + 1;
                q.push({startR, c1});
            }
        }
        
        if (c2 < m) {
            if (city[startR][c2] != 'X' && !vis[startR][c2]) {
                vis[startR][c2] = true;
                dist[startR][c2] = dist[startR][startC] + 1;
                q.push({startR, c2});
            }
        }
    }
    if (dist[endR][endC] == -1) {
        cout << -1 << endl;
    } else {
        cout << dist[endR][endC] - 1 << endl;
    }
    return 0;
}