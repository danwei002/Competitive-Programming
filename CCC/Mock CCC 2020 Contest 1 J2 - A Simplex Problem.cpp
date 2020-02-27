#include <bits/stdc++.h>

using namespace std;

int main() {
    int Uc, Um, K; scanf("%d%d%d", &Uc, &Um, &K);
    int ans = INT_MIN;
    for (int i = 0; i <= K; i++) {ans = max(ans, Uc * i + (K - i) * Um);}
    printf("%d\n", ans);
    return 0;
}