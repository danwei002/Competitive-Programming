#include <bits/stdc++.h>

using namespace std;

int house[25][25];
void travel(int r, int maxR, int c, int maxC, int roomNum) {
    if (r >= 0 and r < maxR and c >= 0 and c < maxC) {
        if (house[r][c] == 0) {
            house[r][c] = roomNum;
            travel(r - 1, maxR, c, maxC, roomNum);
            travel(r + 1, maxR, c, maxC, roomNum);
            travel(r, maxR, c - 1, maxC, roomNum);
            travel(r, maxR, c + 1, maxC, roomNum);
        }
    }
}

int main() {
    int flooring, R, C;
    cin >> flooring >> R >> C;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            char c;
            cin >> c;
            if (c == '.') {
                house[i][j] = 0;
            } else {
                house[i][j] = -1;
            }
        }
    }
    
    int roomNum = 1;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (house[i][j] == 0) {
                travel(i, R, j, C, roomNum);
                roomNum++;
            }
        }
    }
    
    int areas[roomNum - 1];
    memset(areas, 0, sizeof(areas));
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (house[i][j] != -1) {
                areas[house[i][j] - 1]++;
            }
        }
    }
    
    int n = sizeof(areas) / sizeof(areas[0]);
    sort(areas, areas + n, greater<int>());
    int filled = 0;
    for (auto p: areas) {
        if (flooring >= p) {
            flooring -= p;
            filled++;
        } else {
            break;
        }
    }
    if (filled == 1) {
        cout << filled << " room, " << flooring << " square metre(s) left over" << endl;
    } else {
        cout << filled << " rooms, " << flooring << " square metre(s) left over" << endl;
    }
    return 0;
}