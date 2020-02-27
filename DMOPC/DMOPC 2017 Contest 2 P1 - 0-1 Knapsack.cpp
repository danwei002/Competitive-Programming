#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll N;
int main() {
    scanf("%lld", &N);
    ll ans = 0;
    for (ll i = 0; i < N; i++) {
        ll c, v; scanf("%lld%lld", &c, &v);
        if (v > 0) {ans += c;}
    }
    printf("%lld\n", ans);
    return 0;
}