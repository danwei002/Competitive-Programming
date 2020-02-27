#include <bits/stdc++.h>

using namespace std;

int main() {
    int graph[8][8]; int d[8];
    for (int i = 0; i < 8; i++) {for (int j = 0; j < 8; j++) {graph[i][j] = 0; d[i] = 0;}}
    graph[1][7] = 1; graph[1][4] = 1; graph[2][1] = 1; graph[3][4] = 1; graph[3][5] = 1;
    d[1] = 1; d[4] = 2; d[5] = 1; d[7] = 1; 
    int output[7];
    while (true) {
        int x, y; cin >> x >> y;
        if (x == 0 and y == 0) {break;}
        graph[x][y] = 1;
        d[y]++;
    }
    
    int index = 0;
    for (int i = 1; i <= 7; i++) {
        for (int j = 1; j <= 7; j++) {
            if (d[j] == 0) {
                d[j] = -1; output[index] = j; index++;
                for (int k = 1; k <= 7; k++) {
                    if (j != k and graph[j][k] == 1) {d[k]--;}
                }
                break;
            }
        }
    }
    
    if (index != 7) {cout << "Cannot complete these tasks. Going to bed.\n";}
    else {for (auto p: output) {cout << p << " ";}}
    return 0;
}