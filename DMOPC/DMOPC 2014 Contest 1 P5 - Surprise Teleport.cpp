#include <bits/stdc++.h>

using namespace std;

int main() {
    int R, C;
    cin >> R >> C;
    char grid[R][C];
    bool vis[R][C];
    int dist[R][C];
    
    int sr, sc, er, ec;
    cin >> sr >> sc >> er >> ec;
    
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> grid[i][j];
            dist[i][j] = -1;
            vis[i][j] = false;
        }
    }
    
    int T;
    cin >> T;
    vector<pair<int, int>> devices;
    for (int i = 0; i < T; i++) {
        int x, y;
        cin >> x >> y;
        devices.push_back({x, y});
    }
    
    queue<pair<int, int>> q;
    vis[sr][sc] = true;
    dist[sr][sc] = 0;
    q.push({sr, sc});
    while (!q.empty()) {
        sr = q.front().first; sc = q.front().second; q.pop();
        int r1, r2, c1, c2;
        r1 = sr - 1; r2 = sr + 1; c1 = sc - 1; c2 = sc + 1;
        if (r1 >= 0) {
            if (grid[r1][sc] != 'X' and !vis[r1][sc]) {
                vis[r1][sc] = true;
                dist[r1][sc] = dist[sr][sc] + 1;
                q.push({r1, sc});
            }
        }
        
        if (r2 < R) {
            if (grid[r2][sc] != 'X' and !vis[r2][sc]) {
                vis[r2][sc] = true;
                dist[r2][sc] = dist[sr][sc] + 1;
                q.push({r2, sc});
            }
        }
        
        if (c1 >= 0) {
            if (grid[sr][c1] != 'X' and !vis[sr][c1]) {
                vis[sr][c1] = true;
                dist[sr][c1] = dist[sr][sc] + 1;
                q.push({sr, c1});
            }
        }
        
        if (c2 < C) {
            if (grid[sr][c2] != 'X' and !vis[sr][c2]) {
                vis[sr][c2] = true;
                dist[sr][c2] = dist[sr][sc] + 1;
                q.push({sr, c2});
            }
        }
    }
    
    int shortest = INT_MAX;
    for (auto p: devices) {
        if (dist[p.first][p.second] != -1) {
            shortest = min(shortest, dist[p.first][p.second]);
        }
    }
    
    if (shortest < dist[er][ec]) {
        cout << dist[er][ec] - shortest << endl;
        return 0;
    }
    cout << 0 << endl;
    return 0;
}