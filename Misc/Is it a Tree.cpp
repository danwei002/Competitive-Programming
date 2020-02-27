#include <bits/stdc++.h>

using namespace std;

int main() {
    int mat[4][4];
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> mat[i][j];
        }
    }
    
    int branches = 0;
    for (int k = 0; k < 4; k++) {
        for (int l = 0; l < 4; l++) {
            if (mat[k][l] == mat[l][k]) {
                if (mat[k][l] == 1) {
                    branches++;
                }
            } else {
                cout << "No";
                return 0;
            }
        }
    }
    
    vector<int> v[4];
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (mat[i][j] == 1) {
                v[i].push_back(j);
            }
        }
    }
    
    queue<int> q;
    bool vis[4] = {false};
    vis[0] = true;
    q.push(0);
    set<int> visited;
    visited.insert(0);
    while (!q.empty()) {
        int s = q.front(); q.pop();
        for (auto p: v[s]) {
            if (!vis[p]) {
                visited.insert(p);
                vis[p] = true;
                q.push(p);
            }
        }
    }
    
    if (branches == 6 && visited.size() == 4) {
        cout << "Yes";
    } else {
        cout << "No";
    }
}