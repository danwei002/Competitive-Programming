#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> v[N + 1];
    while (true) {
        int x, y;
        cin >> x >> y;
        if (x == 0 and y == 0) {
            break;
        }
        v[y].push_back(x);
    }
    
    long long dp[N + 1] = {0};
    while (v[N].size() != 0) {
        dp[v[N].back()] = 1;
        v[N].pop_back();
    }
    
    for (int i = N - 1; i >= 1; i--) {
        while (v[i].size() != 0) {
            dp[v[i].back()] = dp[v[i].back()] + dp[i];
            v[i].pop_back();
        }
    }
    
    if (dp[1] == -1) {
        cout << 0 << endl;
        return 0;
    }
    cout << dp[1];
}