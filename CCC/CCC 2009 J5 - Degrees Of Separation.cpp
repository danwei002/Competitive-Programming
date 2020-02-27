#include <bits/stdc++.h>

using namespace std;

bool contains(vector<int> vec, int s) {
    for (int i = 0; i < vec.size(); i++) {
        if (vec[i] == s) {
            return true;
        }
    }
    return false;
}

int main() {
    vector<int> fb[50];
    fb[1].push_back(6);
    fb[6].push_back(1);
    fb[2].push_back(6);
    fb[6].push_back(2); 
    fb[6].push_back(7);
    fb[7].push_back(6);
    fb[6].push_back(3);
    fb[3].push_back(6);
    fb[6].push_back(4);
    fb[4].push_back(6);
    fb[5].push_back(6);
    fb[6].push_back(5);
    fb[7].push_back(8);
    fb[8].push_back(7);
    fb[3].push_back(4);
    fb[4].push_back(3);
    fb[4].push_back(5);
    fb[5].push_back(4);
    fb[3].push_back(5);
    fb[5].push_back(3);
    fb[8].push_back(9);
    fb[9].push_back(8);
    fb[3].push_back(15);
    fb[15].push_back(3);
    fb[9].push_back(12);
    fb[12].push_back(9);
    fb[9].push_back(10);
    fb[10].push_back(9);
    fb[10].push_back(11);
    fb[11].push_back(10);
    fb[11].push_back(12);
    fb[12].push_back(11);
    fb[12].push_back(13);
    fb[13].push_back(12);
    fb[13].push_back(15);
    fb[15].push_back(13);
    fb[13].push_back(14);
    fb[14].push_back(13);
    fb[16].push_back(18);
    fb[18].push_back(16);
    fb[18].push_back(17);
    fb[17].push_back(18);
    fb[16].push_back(17);
    fb[17].push_back(16);
    
    while (true) {
        char cmd;
        cin >> cmd;
        int x, y;
        if (cmd == 'i') {
            int x, y;
            cin >> x >> y;
            if (!contains(fb[x], y)) {
                fb[x].push_back(y);
            }
            
            if (!contains(fb[y], x)) {
                fb[y].push_back(x);
            }
        } else if (cmd == 'd') {
            //int x, y;
            cin >> x >> y;
            if (contains(fb[x], y)) {
                fb[x].erase(remove(fb[x].begin(), fb[x].end(), y), fb[x].end());
            }
            
            if (contains(fb[x], y)) {
                fb[y].erase(remove(fb[y].begin(), fb[y].end(), x), fb[y].end());
            }
        } else if (cmd == 'n' or cmd == 'f') {
            //int x;
            cin >> x;
            int total = 0;
            queue<int> q;
            int d[50] = {0};
            bool visited[50] = {false};
            q.push(x);
            int s;
            while (q.size() != 0) {
                s = q.front(); q.pop();
                for (int i = 0; i < fb[s].size(); i++) {
                    if (!visited[fb[s][i]]) {
                        visited[fb[s][i]] = true;
                        d[fb[s][i]] = d[s] + 1;
                        q.push(fb[s][i]);
                    }
                }
            }
            
            int ft = 0;
            if (cmd == 'n') {
                for (int i = 0; i < 50; i++) {
                    if (d[i] == 1) {
                        total++;
                    }
                }
                cout << total << endl;
            } else {
                for (int i = 0; i < 50; i++) {
                    if (d[i] == 2 && i != x) {
                        ft++;
                    }
                }
                cout << ft << endl;
            }
        } else if (cmd == 's') {
            //int x, y;
            cin >> x >> y;
            queue<int> q;
            int d[50] = {0};
            bool visited[50] = {false};
            q.push(x);
            int s;
            while (q.size() != 0) {
                s = q.front(); q.pop();
                for (int i = 0; i < fb[s].size(); i++) {
                    if (!visited[fb[s][i]]) {
                        visited[fb[s][i]] = true;
                        d[fb[s][i]] = d[s] + 1;
                        q.push(fb[s][i]);
                    }
                }
            }
            
            if (d[y] == 0) {
                cout << "Not connected" << endl;
            } else {
                cout << d[y] << endl;
            }
        } else {
            break;
        }
    }
}