#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> book[N + 1];
    
    for (int i = 1; i <= N; i++) {
        int M;
        cin >> M;
        for (int j = 0; j < M; j++) {
            int p;
            cin >> p;
            book[i].push_back(p);
        }
    }
    
    set<int> reachable;
    reachable.insert(1);
    
    bool vis[N + 1] = {false};
    int d[N + 1];
    memset(d, 0, sizeof(d));
    queue<int> q;
    q.push(1);
    vis[1] = true;
    d[1] = 0;
    int s;
    while (q.size() != 0) {
        s = q.front(); q.pop();
        for (auto a: book[s]) {
            if (!vis[a]) {
                reachable.insert(a);
                vis[a] = true;
                d[a] = d[s] + 1;
                q.push(a);
            }
        }
    }
    
    if (reachable.size() == N) {
        cout << "Y" << endl;
    } else {
        cout << "N" << endl;
    }
    
    vector<int> endPgs;
    for (int i = 1; i <= N; i++) {
        if (book[i].size() == 0) {
            endPgs.push_back(i);
        }
    }
    
    int min = INT_MAX;
    for (auto p: endPgs) {
        if (vis[p]) {
            if (d[p] < min) {
                min = d[p];
            }
        }
    }
    
    cout << min + 1 << endl;
}