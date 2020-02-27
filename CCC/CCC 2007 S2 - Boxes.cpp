#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<ll, pll> plll;

int main() {
    ll n; scanf("%lld", &n);
    plll box[n];
    for (int i = 0; i < n; i++) {
        ll l, w, h; scanf("%lld%lld%lld", &l, &w, &h);
        box[i] = {l, {w, h}};
    }
    ll m; scanf("%lld", &m);
    for (int i = 0; i < m; i++) {
        ll l, w, h; scanf("%lld%lld%lld", &l, &w, &h);
        ll ans = INT_MAX;
        for (int j = 0; j < n; j++) {
            ll l2 = box[j].first; ll w2 = box[j].second.first; ll h2 = box[j].second.second;
            if ((l <= l2 and w <= w2 and h <= h2) or (l <= l2 and w <= h2 and h <= w2) or (l <= w2 and w <= l2 and h <= h2) or (l <= w2 and w <= h2 and h <= l2) or (l <= h2 and w <= l2 and h <= w2) or (l <= h2 and w <= w2 and h <= l2)) {
                ans = min(ans, l2 * w2 * h2);
            }
        }
        
        if (ans == INT_MAX) {printf("%s\n", "Item does not fit.");}
        else {printf("%lld\n", ans);}
    }
    return 0;
}