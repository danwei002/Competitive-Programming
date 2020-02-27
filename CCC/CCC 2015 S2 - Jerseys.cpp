#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    int J, A; cin >> J >> A;
    char jer[J + 1]; 
    pair<char, int> req[A + 1]; 
    bool avail[J + 1];
    memset(avail, true, sizeof(avail));
    for (int i = 1; i <= J; i++) {cin >> jer[i];}
    for (int i = 1; i <= A; i++) {
        char c; int d;
        cin >> c >> d;
        req[i] = {c, d};
    }
    
    int ans = 0;
    for (int i = 1; i <= A; i++) {
        if (avail[req[i].second]) {
            if (req[i].first == 'S') {
                ans++;
                avail[req[i].second] = false;
            } else if (req[i].first == 'M') {
                if (jer[req[i].second] == 'M' or jer[req[i].second] == 'L') {
                    ans++;
                    avail[req[i].second] = false;
                }
            } else if (req[i].first == 'L') {
                if (jer[req[i].second] == 'L') {
                    ans++;
                    avail[req[i].second] = false;
                }
            }
        }
        
    }
    cout << ans << "\n";
    return 0;
}