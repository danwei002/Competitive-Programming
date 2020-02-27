#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, M, A, B; scanf("%d%d%d%d", &N, &M, &A, &B);
    if (N == 1 and M == 0) {cout << "GO SHAHIR!" << endl; return 0;}
    vector<int> v[N + 1];
    for (int i = 0; i < M; i++) {
        int X, Y; scanf("%d%d", &X, &Y);
        v[X].push_back(Y); v[Y].push_back(X);
    }
    
    queue<int> q;
    bool vis[N + 1] = {false};
    q.push(A);
    while (!q.empty()) {
        int s = q.front(); q.pop();
        for (auto p: v[s]) {
            if (!vis[p]) {
                vis[p] = true;
                q.push(p);
            }
        }
    }
    
    if (vis[B]) {cout << "GO SHAHIR!" << endl;}
    else {cout << "NO SHAHIR!" << endl;}
}