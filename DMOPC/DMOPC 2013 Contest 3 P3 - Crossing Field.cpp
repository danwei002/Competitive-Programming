#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, H;
    scanf("%d%d", &N, &H);
    int grid[N][N];
    bool vis[N][N];
    if (N == 0) {cout << "no" << endl; return 0;}
    if (N == 1) {cout << "yes" << endl; return 0;}
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &grid[i][j]);
            vis[i][j] = false;
        }
    }
    
    int sr = 0; int sc = 0;
    queue<pair<int, int>> q;
    q.push({0, 0});
    vis[0][0] = true;
    while (!q.empty()) {
        sr = q.front().first; sc = q.front().second; q.pop();
        int r1, r2, c1, c2;
        r1 = sr - 1; r2 = sr + 1; c1 = sc - 1; c2 = sc + 1;
        if (r1 >= 0) {
            int diff = abs(grid[sr][sc] - grid[r1][sc]);
            if (!vis[r1][sc] and diff <= H) {
                vis[r1][sc] = true;
                q.push({r1, sc});
            }
        }
        
        if (r2 < N) {
            int diff = abs(grid[sr][sc] - grid[r2][sc]);
            if (!vis[r2][sc] and diff <= H) {
                vis[r2][sc] = true;
                q.push({r2, sc});
            }
        }
        
        if (c1 >= 0) {
            int diff = abs(grid[sr][sc] - grid[sr][c1]);
            if (!vis[sr][c1] and diff <= H) {
                vis[sr][c1] = true;
                q.push({sr, c1});
            }
        }
        
        if (c2 < N) {
            int diff = abs(grid[sr][sc] - grid[sr][c2]);
            if (!vis[sr][c2] and diff <= H) {
                vis[sr][c2] = true;
                q.push({sr, c2});
            }
        }
    }
    
    if (vis[N - 1][N - 1]) {cout << "yes" << endl;}
    else {cout << "no" << endl;}
    return 0;
}