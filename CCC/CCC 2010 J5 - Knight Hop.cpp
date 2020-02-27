#include <bits/stdc++.h>

using namespace std;

int main() {
    int startX, startY, endX, endY;
    cin >> startX >> startY >> endX >> endY;
    
    int dist[8][8];
    bool vis[8][8];
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            dist[i][j] = 0;
            vis[i][j] = false;
        }
    }
    startX -= 1;
    startY = 8 - startY;
    
    queue<pair<int, int>> coords;
    coords.push({startX, startY});
    vis[startX][startY] = true;
    dist[startX][startY] = 0;
    while (!coords.empty()) {
        int x1, x2, x3, x4, y1, y2, y3, y4;
        startX = coords.front().first; startY = coords.front().second; coords.pop();
        x1 = startX - 1; x2 = startX + 1; x3 = startX + 2; x4 = startX - 2;
        y1 = startY - 1; y2 = startY + 1; y3 = startY + 2; y4 = startY - 2;
        if (x1 < 8 and x1 >= 0) {
            if (y3 < 8 and y3 >= 0) {
                if (!vis[x1][y3]) {
                    dist[x1][y3] = dist[startX][startY] + 1;
                    vis[x1][y3] = true;
                    coords.push({x1, y3});
                }
            }
            
            if (y4 < 8 and y4 >= 0) {
                if (!vis[x1][y4]) {
                    dist[x1][y4] = dist[startX][startY] + 1;
                    vis[x1][y4] = true;
                    coords.push({x1, y4});
                }
            }
        }
        
        if (x2 < 8 and x2 >= 0) {
            if (y3 < 8 and y3 >= 0) {
                if (!vis[x2][y3]) {
                    dist[x2][y3] = dist[startX][startY] + 1;
                    vis[x2][y3] = true;
                    coords.push({x2, y3});
                }
            }
            
            if (y4 < 8 and y4 >= 0) {
                if (y3 < 8 and y3 >= 0) {
                    if (!vis[x2][y4]) {
                        dist[x2][y4] = dist[startX][startY] + 1;
                        vis[x2][y4] = true;
                        coords.push({x2, y4});
                    }
                }
            }
        }
        
        if (x3 < 8 and x3 >= 0) {
            if (y1 < 8 and y1 >= 0) {
                if (!vis[x3][y1]) {
                    dist[x3][y1] = dist[startX][startY] + 1;
                    vis[x3][y1] = true;
                    coords.push({x3, y1});
                }
            }
            
            if (y2 < 8 and y2 >= 0) {
                if (!vis[x3][y2]) {
                    dist[x3][y2] = dist[startX][startY] + 1;
                    vis[x3][y2] = true;
                    coords.push({x3, y2});
                }
            }
        }
        
        if (x4 < 8 and x4 >= 0) {
            if (y1 < 8 and y1 >= 0) {
                if (!vis[x4][y1]) {
                    dist[x4][y1] = dist[startX][startY] + 1;
                    vis[x4][y1] = true;
                    coords.push({x4, y1});
                }
            }
            
            if (y2 < 8 and y2 >= 0) {
                if (!vis[x4][y2]) {
                    dist[x4][y2] = dist[startX][startY] + 1;
                    vis[x4][y2] = true;
                    coords.push({x4, y2});
                }
            }
        }
    }
    cout << dist[endX - 1][8 - endY] << endl;
}