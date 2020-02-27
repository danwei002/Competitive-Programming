#include <bits/stdc++.h>

using namespace std;

int main() {
    int N; int M;
    scanf("%d", &N); scanf("%d", &M);
    vector<int> v[N + 1];
    
    for (int i = 0; i < M; i++) {
        int e; int f;
        scanf("%d", &e); scanf("%d", &f);
        v[e].push_back(f);
    }
    
    bool visited[N + 1] = {false};
    queue<int> q;
    int d[N + 1] = {0};
    int s;
    q.push(1);
    bool b = false;
    for (int a = 1; a < N + 1; a++) {
        while (q.size() != 0) {
            s = q.front(); q.pop();
            for (int i = 0; i < v[s].size(); i++) {
                if (!visited[v[s][i]]) {
                    visited[v[s][i]] = true;
                    q.push(v[s][i]);
                    d[v[s][i]] = d[s] + 1;
                }
            }
        }
    
        for (int j = 1; j < N + 1; j++) {
            if (d[j] >= 6) {
                for (int k = 0; k < v[j].size(); k++) {
                    if (v[j][k] == a) {
                        cout << "YES";
                        return 0;
                    }
                }
            } 
        }
    }
    cout << "NO";
}