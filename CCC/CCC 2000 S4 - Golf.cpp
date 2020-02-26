#include <bits/stdc++.h>

using namespace std;

int main() {
    int dist, numClubs;
    cin >> dist >> numClubs;
    
    int clubs[numClubs];
    for (int i = 0 ; i < numClubs; i++) {
        cin >> clubs[i];
    }
    
    int dp[dist + 1];
    for (int i = 0; i <= dist; i++) {
        dp[i] = -1;
    }
    
    dp[0] = 0;
    for (int i = 1; i <= dist; i++) {
        int min = INT_MAX;
        for (auto p: clubs) {
            int s = i - p;
            if (s >= 0 && dp[s] >= 0 && dp[s] < min) {
                min = dp[s];
            }
        }
        
        if (min != INT_MAX) {
            dp[i] = min + 1;
        } else {
            dp[i] = -1;
        }
    }
    
    if (dp[dist] == -1) {
        cout << "Roberta acknowledges defeat.";
    } else {
        cout << "Roberta wins in " << dp[dist] << " strokes.";
    }
}