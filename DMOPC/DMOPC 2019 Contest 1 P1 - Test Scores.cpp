#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        double n, a, b, t;
        cin >> n >> a >> b >> t;
        double min = (t + b * n) / (a + b);
        int s = (int) ceil(min);
        if (s > n) {
            cout << -1 << endl;
        } else {
            cout << s << endl;
        }
    }
}