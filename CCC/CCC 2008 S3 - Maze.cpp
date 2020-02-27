#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int r, c;
        cin >> r >> c;
        char city[r][c];
        int dist[r][c];
        bool vis[r][c];
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cin >> city[i][j];
                dist[i][j] = -1;
                vis[i][j] = false;
            }
            
        }
        
        if (city[0][0] == '*') {
            cout << -1 << endl;
            continue;
        }
        
        int startR = 0; int startC = 0;
        queue<pair<int, int>> q;
        q.push({startR, startC});
        dist[0][0] = 0;
        vis[0][0] = true;
        while (!q.empty()) {
            startR = q.front().first; startC = q.front().second; q.pop();
            if (city[startR][startC] == '+') {
                int r1, r2, c1, c2;
                r1 = startR - 1; r2 = startR + 1; c1 = startC - 1; c2 = startC + 1;
                if (r1 >= 0) {
                    if (city[r1][startC] != '*' && !vis[r1][startC]) {
                        vis[r1][startC] = true;
                        dist[r1][startC] = dist[startR][startC] + 1;
                        q.push({r1, startC});
                    }
                }
                
                if (r2 < r) {
                    if (city[r2][startC] != '*' && !vis[r2][startC]) {
                        vis[r2][startC] = true;
                        dist[r2][startC] = dist[startR][startC] + 1;
                        q.push({r2, startC});
                    }
                }
                
                if (c1 >= 0) {
                    if (city[startR][c1] != '*' && !vis[startR][c1]) {
                        vis[startR][c1] = true;
                        dist[startR][c1] = dist[startR][startC] + 1;
                        q.push({startR, c1});
                    }
                }
                
                if (c2 < c) {
                    if (city[startR][c2] != '*' && !vis[startR][c2]) {
                        vis[startR][c2] = true;
                        dist[startR][c2] = dist[startR][startC] + 1;
                        q.push({startR, c2});
                    }
                }
            } else if (city[startR][startC] == '-') {
                int c1, c2;
                c1 = startC - 1; c2 = startC + 1;
                 if (c1 >= 0) {
                    if (city[startR][c1] != '*' && !vis[startR][c1]) {
                        vis[startR][c1] = true;
                        dist[startR][c1] = dist[startR][startC] + 1;
                        q.push({startR, c1});
                    }
                }
                
                if (c2 < c) {
                    if (city[startR][c2] != '*' && !vis[startR][c2]) {
                        vis[startR][c2] = true;
                        dist[startR][c2] = dist[startR][startC] + 1;
                        q.push({startR, c2});
                    }
                }
            } else if (city[startR][startC] == '|') {
                int r1, r2;
                r1 = startR - 1; r2 = startR + 1;
                if (r1 >= 0) {
                    if (city[r1][startC] != '*' && !vis[r1][startC]) {
                        vis[r1][startC] = true;
                        dist[r1][startC] = dist[startR][startC] + 1;
                        q.push({r1, startC});
                    }
                }
                
                if (r2 < r) {
                    if (city[r2][startC] != '*' && !vis[r2][startC]) {
                        vis[r2][startC] = true;
                        dist[r2][startC] = dist[startR][startC] + 1;
                        q.push({r2, startC});
                    }
                }
            }
        }
        if (!vis[r - 1][c - 1]) {
            cout << -1 << endl;
        } else {
            cout << dist[r - 1][c - 1] + 1 << endl;
        }
    }
    return 0;
}