#include <bits/stdc++.h>
using namespace std;
int main() {
    int N, M;
    cin >> N >> M;
    char grid[N][M];
    int startR, startC;
    bool hasDot[N][M];
    int dist[N][M];
    bool vis[N][M];
    bool seen[N][M];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j  < M; j++) {
            cin >> grid[i][j];
            vis[i][j] = false;
            if (grid[i][j] == 'S') {startR = i; startC = j; hasDot[i][j] = true;} 
            else if (grid[i][j] == '.') {hasDot[i][j] = true; dist[i][j] = -1;}
            else {hasDot[i][j] = false;}
            seen[i][j] = false;
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (grid[i][j] == 'C') {
                for (int k = j; k < M; k++) {
                    if (grid[i][k] == 'W') {break;}
                    else {seen[i][k] = true;}
                }
                for (int k = j; k >= 0; k--) {
                    if (grid[i][k] == 'W') {break;} 
                    else {seen[i][k] = true;}
                }
                for (int k = i; k < N; k++) {
                    if (grid[k][j] == 'W') {break;}
                    else {seen[k][j] = true;}
                }
                for (int k = i; k >= 0; k--) {
                    if (grid[k][j] == 'W') {break; } 
                    else {seen[k][j] = true;}
                }
            }
        }
    }
    if (!seen[startR][startC]) {
        dist[startR][startC] = 0;
        vis[startR][startC] = true;
        queue<pair<int, int>> coords;
        coords.push({startR, startC});
        while (!coords.empty()) {
            startR = coords.front().first; startC = coords.front().second; coords.pop();
            int r1, r2, c1, c2;
            r1 = startR - 1; r2 = startR + 1; c1 = startC - 1; c2 = startC + 1;
            int r = startR; int c = startC;
            if (r1 < N && r1 > 0  && !(grid[r1][startC] == 'W')) {
                int conv = 0;
                while (grid[r1][c] == 'L' or grid[r1][c] == 'R' or grid[r1][c] == 'U' or grid[r1][c] == 'D') {
                    if (grid[r1][c] == 'L') {c--; conv++;}
                    else if (grid[r1][c] == 'R') {c++; conv++;}
                    else if (grid[r1][c] == 'U') {r1--; conv++;}
                    else if (grid[r1][c] == 'D') {r1++; conv++;}
                    if (conv > 4) {break;}
                }
                if (r1 < N && r1 > 0 && c < M && c > 0) {
                    if (hasDot[r1][c] && !vis[r1][c] && !seen[r1][c]) {
                        dist[r1][c] = dist[startR][startC] + 1;
                        vis[r1][c] = true;
                        coords.push({r1, c});
                    }
                }
            }
            r = startR; c = startC;
            if (r2 < N && r2 > 0 && !(grid[r2][startC] == 'W')) {
                int conv = 0;
                while (grid[r2][c] == 'L' or grid[r2][c] == 'R' or grid[r2][c] == 'U' or grid[r2][c] == 'D') {
                    if (grid[r2][c] == 'L') {c--; conv++;}
                    else if (grid[r2][c] == 'R') {c++; conv++;}
                    else if (grid[r2][c] == 'U') {r2--; conv++;}
                    else if (grid[r2][c] == 'D') {r2++; conv++;}
                    if (conv > 4) {break;}
                }
                if (r2 < N && r2 > 0 && c < M && c > 0) {
                    if (hasDot[r2][c] && !vis[r2][c] && !seen[r2][c]) {
                        dist[r2][c] = dist[startR][startC] + 1;
                        vis[r2][c] = true;
                        coords.push({r2, c});
                    }
                }
            }
            r = startR; c = startC;
            if (c1 < M && c1 > 0 && !(grid[startR][c1] == 'W')) {
                int conv = 0;
                while (grid[r][c1] == 'L' or grid[r][c1] == 'R' or grid[r][c1] == 'U' or grid[r][c1] == 'D') {
                    if (grid[r][c1] == 'L') {c1--; conv++;}
                    else if (grid[r][c1] == 'R') {c1++; conv++;}
                    else if (grid[r][c1] == 'U') {r--; conv++;}
                    else if (grid[r][c1] == 'D') {r++; conv++;}
                    if (conv > 4) {break;}
                }
                if (r < N && r > 0 && c1 < M && c1 > 0) {
                    if (hasDot[r][c1] && !vis[r][c1] && !seen[r][c1]) {
                        dist[r][c1] = dist[startR][startC] + 1;
                        vis[r][c1] = true;
                        coords.push({r, c1});
                    }
                }
            }
            r = startR; c = startC;
            if (c2 < M && c2 > 0 && !(grid[startR][c2] == 'W')) {
                int conv = 0;
                while (grid[r][c2] == 'L' or grid[r][c2] == 'R' or grid[r][c2] == 'U' or grid[r][c2] == 'D') {
                    if (grid[r][c2] == 'L') {c2--; conv++;}
                    else if (grid[r][c2] == 'R') {c2++; conv++;}
                    else if (grid[r][c2] == 'U') {r--; conv++;}
                    else if (grid[r][c2] == 'D') {r++; conv++;}
                    if (conv > 4) {break;}
                }
                if (r < N && r > 0 && c2 < M && c2 > 0) {
                    if (hasDot[r][c2] && !vis[r][c2] && !seen[r][c2]) {
                        dist[r][c2] = dist[startR][startC] + 1;
                        vis[r][c2] = true;
                        coords.push({r, c2});
                    }
                }
            }
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (hasDot[i][j] && !(grid[i][j] == 'S')) {
                if (!seen[i][j]) {cout << dist[i][j] << endl;} 
                else {cout << -1 << endl;}
            }
        }
    }
}