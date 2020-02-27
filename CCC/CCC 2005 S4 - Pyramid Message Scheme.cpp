#include <bits/stdc++.h>

using namespace std;

int main() {
    int L;
    cin >> L;
    for (int i = 0; i < L; i++) {
        int n;
        cin >> n;
        string a[n];
        string b[n];
        for (int j = 0; j < n; j++) {
            cin >> a[j];
        }
        int mx = 0;
        b[0] = a[n - 1];
        int c = 0;
        for (int j = 0; j < n; j++) {
            int s = 0;
            while (s <= c and a[j] != b[s]) {s++;}
            b[s] = a[j];
            c = s;
            mx = max(mx, c);
        }
        
        cout << n * 10 - 2 * mx * 10 << "\n";
    }
    return 0;
}