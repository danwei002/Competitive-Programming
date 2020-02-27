#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    
    for (int i = 0; i < t; i++) {
        int l, w, sr, sc, er, ec;
        cin >> l >> w;
        char grid[w][l];
        bool vis[w][l];
        int dist[w][l];
        for (int j = 0; j < w; j++) {
            for (int k = 0; k < l; k++) {
                cin >> grid[j][k];
                if (grid[j][k] == 'C') {sr = j; sc = k;}
                if (grid[j][k] == 'W') {er = j; ec = k;}
                vis[j][k] = false;
                dist[j][k] = -1;
            }
        }
        
        queue<pair<int, int>> q;
        vis[sr][sc] = true;
        dist[sr][sc] = 1;
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
            
            if (r2 < w) {
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
            
            if (c2 < l) {
                if (grid[sr][c2] != 'X' and !vis[sr][c2]) {
                    vis[sr][c2] = true;
                    dist[sr][c2] = dist[sr][sc] + 1;
                    q.push({sr, c2});
                }
            }
        }
        
        if (dist[er][ec] <= 60 and dist[er][ec] != -1) {cout << dist[er][ec] - 1 << endl;}
        else {cout << "#notworth" << endl;}
    }
    return 0;
}