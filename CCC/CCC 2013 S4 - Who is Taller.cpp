#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, M;
    scanf("%d", &N); scanf("%d", &M);
    vector<int> g[N + 1];
    for (int i = 0; i < M; i++) {
        int x, y;
        scanf("%d", &x); scanf("%d", &y);
        g[x].push_back(y);
    }
    
    int p, q;
    scanf("%d", &p); scanf("%d", &q);
    
    queue<int> qu;
    bool visited[N + 1] = {false};
    int s;
    qu.push(p);
    bool b = false;
    while (qu.size() != 0) {
        int s = qu.front(); qu.pop();
        for (int i = 0; i < g[s].size(); i++) {
            if (!visited[g[s][i]]) {
                visited[g[s][i]] = true;
                qu.push(g[s][i]);
            }
            
            if (g[s][i] == q) {
                cout << "yes";
                b = true;
                break;
            }
        }
        if (b) {
            break;
        }
    }
    
    if (!b) {
        queue<int> q2;
        bool visited2[N + 1] = {false};
        int s2;
        q2.push(q);
        while (q2.size() != 0) {
            int s2 = q2.front(); q2.pop();
            for (int i = 0; i < g[s2].size(); i++) {
                if (!visited[g[s2][i]]) {
                    visited[g[s2][i]] = true;
                    q2.push(g[s2][i]);
                }
                
                if (g[s2][i] == p) {
                    cout << "no";
                    b = true;
                    break;
                }
            }
            if (b) {
                break;
            }
        }
        
        if (!b) {
            cout << "unknown";
        }
    }
}