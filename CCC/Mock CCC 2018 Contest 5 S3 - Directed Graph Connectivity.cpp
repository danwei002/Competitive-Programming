#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    
    if (N == 0) {
        return 0;
    }
    
    if (N == 1 or M == 1) {
        cout << "NO" << endl;
        return 0;
    }
    
    vector<int> v[N + 1];
    pair<int, int> edge[M];
    for (int i = 0; i < M; i++) {
        int s, t;
        cin >> s >> t;
        v[s].push_back(t);
        edge[i] = {s, t};
    }
    
    for (auto p: edge) {
        int a = p.first; int b = p.second;
        v[a].erase(remove(v[a].begin(), v[a].end(), b), v[a].end());
        queue<int> q;
        bool vis[N + 1] = {false};
        q.push(1);
        vis[1] = true;
        while (!q.empty()) {
            int s = q.front(); q.pop();
            for (auto k: v[s]) {
                if (!vis[k]) {
                    vis[k] = true;
                    q.push(k);
                }
            }
        }
        
        if (!vis[N]) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }
        v[a].push_back(b);
    }
}