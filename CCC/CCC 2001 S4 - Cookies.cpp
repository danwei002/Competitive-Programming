#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    pair<double, double> c[n];
    for (int i = 0; i < n; i++) {
        double x, y;
        cin >> x >> y;
        c[i] = {x, y};
    }
    
    double ans = 0.00;
    double d;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                double x = sqrt(pow((c[i].first - c[j].first), 2) + pow((c[i].second - c[j].second), 2));
                double y = sqrt(pow((c[j].first - c[k].first), 2) + pow((c[j].second - c[k].second), 2));
                double z = sqrt(pow((c[i].first - c[k].first), 2) + pow((c[i].second - c[k].second), 2));
                double s = (x + y + z) / 2;
                d = 0;
                if (s == 0 or (x * x + y * y - z  * z < 0) or (y * y + z * z - x * x < 0) or (x * x + z * z - y * y < 0)) {
                    if (x > d) {d = x;}
                    if (y > d) {d = y;}
                    if (z > d) {d = z;}
                } else {
                    d = 2 * (x * y * z) / (4 * (sqrt(s * (s - x) * (s - y) * (s - z))));
                }
                if (d > ans) {
                    ans = d;
                }
            }
        }
    }
    
    cout << fixed << setprecision(2) << ans << endl;
    return 0;
}