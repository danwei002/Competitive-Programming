#include <bits/stdc++.h>

using namespace std;

int main() {
    int N; scanf("%d", &N);
    pair<long double, long double> obs[N];
    for (int i = 0; i < N; i++) {
        long double T, X;
        scanf("%Lf%Lf", &T, &X);
        obs[i] = {T, X};
    }
    int n = sizeof(obs) / sizeof(obs[0]);
    sort(obs, obs + n);
    long double ans = DBL_MIN;
    for (int i = 0; i < N - 1; i++) {
        long double newSpeed = abs(obs[i].second - obs[i + 1].second) / abs(obs[i].first - obs[i + 1].first);
        ans = fmax(ans, newSpeed);
    }
    printf("%.6Lf", ans);
    return 0;
}