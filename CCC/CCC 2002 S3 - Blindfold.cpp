#include <bits/stdc++.h>

using namespace std;

int main() {
    int r, c, m;
    cin >> r >> c;
    char backyard[r][c];
    char output[r][c];
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> backyard[i][j];
            output[i][j] = backyard[i][j];
        }
    }
    
    cin >> m;
    char instruct[m];
    for (int q = 0; q < m; q++) {
        cin >> instruct[q];
    }
    
    // 0 - North, 1 - East, 2 - South, 3 - West
    for (int a = 0; a < r; a++) {
        for (int b = 0; b < c; b++) {
            for (int n = 0; n < 4; n++) {
                int rVal = a;
                int cVal = b;
                int dir = n;
                bool noPath = false;
                for (int s = 0; s < m; s++) {
                    if (rVal >= 0 && rVal < r && cVal >= 0 && cVal < c) {
                        if (backyard[rVal][cVal] == 'X') {
                            noPath = true;
                        }
                    } else {
                        noPath = true;
                    }
                    
                    if (!noPath) {
                        if (dir == 0) {
                            if (instruct[s] == 'L') {
                                dir = 3;
                            } else if (instruct[s] == 'R') {
                                dir = 1;
                            } else if (instruct[s] == 'F') {
                                rVal--;
                            }
                        } else if (dir == 1) {
                            if (instruct[s] == 'L') {
                                dir = 0;
                            } else if (instruct[s] == 'R') {
                                dir = 2;
                            } else if (instruct[s] == 'F') {
                                cVal++;
                            }
                        } else if (dir == 2) {
                            if (instruct[s] == 'L') {
                                dir = 1;
                            } else if (instruct[s] == 'R') {
                                dir = 3;
                            } else if (instruct[s] == 'F') {
                                rVal++;
                            }
                        } else if (dir == 3) {
                            if (instruct[s] == 'L') {
                                dir = 2;
                            } else if (instruct[s] == 'R') {
                                dir = 0;
                            } else if (instruct[s] == 'F') {
                                cVal--;
                            }
                        }
                    }
                    
                    if (rVal >= 0 && rVal < r && cVal >= 0 && cVal < c) {
                        if (backyard[rVal][cVal] == 'X') {
                            noPath = true;
                        }
                    } else {
                        noPath = true;
                    }
                }
                
                if (!noPath) {
                    if (rVal >= 0 && rVal < r && cVal >= 0 && cVal < c) {
                        if (backyard[rVal][cVal] == '.') {
                            output[rVal][cVal] = '*';
                        }
                    }
                }
            }
        }
    }
    
    for (int x = 0; x < r; x++) {
        for (int y = 0; y < c; y++) {
            cout << output[x][y];
        }
        cout << endl;
    }
}