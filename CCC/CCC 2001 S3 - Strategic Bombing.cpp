#include <bits/stdc++.h> 
using namespace std; 

int main() { 
    vector<string> roads;
    vector<int> network[26];
    
    int n = 0;
    while (true) {
        string s;
        cin >> s;
        if (s == "**") {
            break;
        }
        roads.push_back(s);
        
        int f, e;
        f = (int) s.at(0) - 65;
        e = (int) s.at(1) - 65;
        network[f].push_back(e);
        network[e].push_back(f);
        n++;
    }
    
    int dst = 1;
    int ct = 0;
    for (auto p: roads) {
        bool vis[26] = {false};
        queue<int> q;
        q.push(0);
        vis[0] = true;
        while (!q.empty()) {
            int s = q.front(); q.pop();
            for (auto c: network[s]) {
                int a = (int) p.at(0) - 65;
                int b = (int) p.at(1) - 65;
                if (!vis[c] && !(s == a && c == b) && !(s == b && c == a)) {
                    vis[c] = true;
                    q.push(c);
                }
            }
        }
        
        if (!vis[dst]) {
            cout << p << endl;
            ct++;
        }
    }
    
    cout << "There are " << ct << " disconnecting roads." << endl;
}