#include <bits/stdc++.h>

using namespace std;

int main() {
    int M, Q;
    cin >> M >> Q;
    string ppl[Q];
    int times[Q];
    
    for (int i = 0; i < Q; i++) {
        string name;
        int t;
        cin >> name >> t;
        ppl[i] = name;
        times[i] = t;
    }
    
    int dp[Q + 1];
    int gp[Q + 1];
    for (int i = 0 ; i <= Q ; i++)
	{
	    dp[i] = INT_MAX;
	    gp[i] = -1;
	}
    
    dp[0] = 0;
    gp[0] = 0;
    for (int i = 0; i <= Q; i++) {
        int cur = 0;
        for (int j = 1; j <= M && i + j - 1 < Q; j++) {
            cur = max(cur, times[i + j - 1]);
            if (dp[i] + cur < dp[i + j]) {
                dp[i + j] = dp[i] + cur;
                gp[i + j] = j;
            }
        }
    }
    
    cout << "Total Time: " << dp[Q] << endl;
    
    int ln[Q + 1];
	int a = Q;
	int b = 1;
	while (gp[a] != 0) {
	    ln[b++] = gp[a];
	    a -= gp[a];
	}
	int c = 0;
	for (int i = b - 1 ; i > 0 ; i--) {
	    for (int j = 0 ; j < ln[i]; j++) {
	        cout << ppl[c++] << " ";
	    }
	    cout << endl;
	}

}