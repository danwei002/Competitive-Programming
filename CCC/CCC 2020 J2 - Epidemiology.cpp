#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ll P, N, R; scanf("%lld%lld%lld", &P, &N, &R);
    ll total = N;
    ll nC = N;
    int day = 0;
    while (total <= P) {
        day++;
        nC *= R;
        total += nC;
    }
    printf("%d\n", day);
    return 0;
}