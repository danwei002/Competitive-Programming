#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll N; 
string s;
vector<ll> v;
int main() {
    cin >> N >> s;
    for (ll i = 0; i < s.length(); i++) {
        if (s.at(i) == '1') {v.push_back(i);}
    }
    
    ll ans = 0;
    if (v.size() == 1) {
        for (ll i = v[0]; i >= 0; i--) {ans += abs(i - v[0]);}
        for (ll i = v[0]; i < s.length(); i++) {ans += abs(i - v[0]);}
    } else {
        for (ll i = v[0]; i >= 0; i--) {ans += abs(i - v[0]);}
        ll index = 0;
        ll curr = v[index];
        ll nxt = v[index + 1];
        for (ll i = v[0] + 1; i < s.length(); i++) {
            if (index == v.size() - 1) {ans += abs(i - curr);}
            else {
                curr = v[index];
                nxt = v[index + 1];
                ans += min(abs(i - curr), abs(i - nxt));
                if (i == nxt) {
                    curr = nxt;
                    index++;
                }
            }
        }
    }
    printf("%lld\n", ans);
}
