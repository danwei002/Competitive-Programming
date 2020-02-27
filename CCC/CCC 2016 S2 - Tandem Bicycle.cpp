#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ll qType, N;
    scanf("%lld%lld", &qType, &N);
    ll dmoj[N]; ll peg[N];
    for (ll i = 0; i < N; i++) {scanf("%lld", &dmoj[i]);}
    for (ll i = 0; i < N; i++) {scanf("%lld", &peg[i]);}
    
    ll total = 0;
    if (qType == 2) {
        sort(dmoj, dmoj + N); sort(peg, peg + N);
        for (ll i = 0; i < N; i++) {total += max(dmoj[i], peg[N - 1 - i]);}
        printf("%lld\n", total);
    } else {
        sort(dmoj, dmoj + N); sort(peg, peg + N);
        for (ll i = 0; i < N; i++) {total += max(dmoj[i], peg[i]);}
        printf("%lld\n", total);
    }
    return 0;
}