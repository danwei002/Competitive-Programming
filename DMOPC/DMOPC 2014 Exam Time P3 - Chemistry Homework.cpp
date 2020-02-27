#include <bits/stdc++.h>

using namespace std;

int occ(vector<int> v, int i) {
    int res = 0;
    for (auto p: v) {
        if (p == i) {res++;}
    }
    return res;
}

int main() {
    int n, m;
    cin >> n >> m;
    int v[n + 1][n + 1];
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            v[i][j] = 0;
        }
    }
    
    int a[n + 1] = {0};
    bool isCarbon[n + 1] = {false};
    for (int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        v[x][y]++;
        v[y][x]++;
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            a[i] += v[i][j];
        }
        
        if (a[i] == 1 or a[i] == 4) {continue;}
        cout << "Impossible\n"; return 0;
    }

    int C = 0; int H = 0;
    for (auto p: a) {
        if (p == 1) {H++;}
        else if (p == 4) {C++;}
    }
    
    int bond = 0;
    bool vis[n + 1] = {false};
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            vis[i] = true;
            for (int j = 1; j <= n; j++) {
                if (!vis[j]) {
                    if (v[i][j] == 2 and a[i] == 4 and a[j] == 4) {bond += 615;}
                    else if (v[i][j] == 1 and a[i] == 4 and a[j] == 4) {bond += 346;}
                    else if (v[i][j] == 1 and (a[i] == 4 and a[j] == 1) or (a[i] == 1 and a[j] == 4)) {bond += 413;}
                }
            }
        }
    }
    
    cout << bond << "\n";
    if (C == 1 and H == 1) {cout << "CH\n";}
    else if (C == 1 and H != 1) {cout << "CH" << H << "\n";}
    else if (C != 1 and H == 1) {cout << "C" << C << "H\n";}
    else {cout << "C" << C << "H" << H << "\n";}
    return 0;
}