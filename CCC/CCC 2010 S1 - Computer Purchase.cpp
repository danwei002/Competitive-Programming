#include <bits/stdc++.h>

using namespace std;

bool sortbysec(const pair<string ,int> &a, const pair<string, int> &b) { 
    return a.second < b.second; 
} 

int main() {
    int n;
    cin >> n;
    string pc1, pc2;
    int top1, top2;
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        string s;
        cin >> s;
        cout << s;
        return 0;
    } 
    
    string s;
    cin >> s;
    int R, S, D;
    cin >> R >> S >> D;
    int v = 2 * R + 3 * S + D;
    top1 = v;
    pc1 = s;
    for (int i = 1; i < n; i++) {
        cin >> s;
        cin >> R >> S >> D;
        v = 2 * R + 3 * S + D;
        if (v > top1 or (v == top1 and s.compare(pc1) < 0)) {
            top2 = top1;
            pc2 = pc1;
            top1 = v;
            pc1 = s;
        } else if (v > top2 or (v == top2 and s.compare(pc2) < 0)) {
            top2 = v;
            pc2 = s;
        }
    }
    cout << pc1 << endl << pc2;
}