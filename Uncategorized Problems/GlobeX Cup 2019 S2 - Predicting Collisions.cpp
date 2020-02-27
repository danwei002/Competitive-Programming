#include <bits/stdc++.h>

using namespace std;

vector<double> func;
double fn(double d) {
    double ans = 0.0;
    for (int i = 0; i < func.size(); i++) {
        ans += func[i] * pow(d, func.size() - i - 1); 
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    double f[N + 1];
    for (int i = 0; i <= N; i++) {
        cin >> f[i];
    }
    
    int M;
    cin >> M;
    double g[M + 1];
    for (int i = 0; i <= M; i++) {
        cin >> g[i];
    }
    
    if (N == M) {
        for (int i = 0; i <= N; i++) {func.push_back(f[i] - g[i]);}
    } else if (N > M) {
        int diff = N - M;
        for (int i = 0; i < diff; i++) {func.push_back(f[i]);}
        for (int j = 0; j <= M; j++) {func.push_back(f[j + diff] - g[j]);}
    } else if (M > N) {
        int diff = M - N;
        for (int i = 0; i < diff; i++) {func.push_back(g[i]);}
        for (int j = 0; j <= N; j++) {func.push_back(g[j + diff] - f[j]);}
    }
    
    double a, b, ans;
    cin >> a >> b;
    double lo = a; double hi = b; double mid;
    for (int i = 0; i < 50; i++) {
        mid = (lo + hi) / 2;
        ans = fn(mid);
        a = fn(lo);
        b = fn(hi);
        if ((a < 0.0 and ans < 0.0) or (a > 0.0 and ans > 0.0)) {
            lo = mid;
        } else {
            hi = mid;
        }
    }
    cout << fixed << setprecision(8) << mid << "\n";
}