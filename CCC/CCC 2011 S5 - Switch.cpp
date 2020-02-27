#include <bits/stdc++.h>

using namespace std;

int main() {
    int K; scanf("%d", &K);
    int lights[K];
    for(int i = 0; i < K; i++) {scanf("%d", &lights[i]);}
    vector<int> v1; vector<int> v2;
    int s = 0;
    v1.push_back(0); v2.push_back(0);
    for (int i = 0; i < K; i++) {
        if (lights[i] == 1) {
            if (v2[s] == 0) {v1[s] = i; v2[s] = i;}
            v2[s] = v2[s] + 1;
        } else if(v2[s] != 0) {
            s = s + 1;
            v1.push_back(0); v2.push_back(0);
        }
    }
    if(v2[s] == 0) {v1.pop_back(); v2.pop_back();}
    s = v1.size(); int dp[s + 1] = {0}; int mx = 100000;
    for(int i = s - 1; i >= 0; i--) {
        dp[i] = mx; int j = i; int o = 0; int l, t;
        while(j < s && v2[j] - v1[i] <= 7) {
            o = o + v2[j] - v1[j]; l = max(4, v2[j] - v1[i]); t = l - o;
            if(l == 6 and lights[v1[i] + 2] == 1 and lights[v1[i] + 3] == 1) {t = mx;}
            else if(l == 7 and lights[v1[i] + 3] == 1) {t = mx;}
            dp[i] = min(dp[i], t + dp[j + 1]); j++;
        }
    }
    printf("%d\n", dp[0]);
}