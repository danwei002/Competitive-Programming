#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, min, max;
    cin >> n >> min >> max;
    int s = 0;
    for (int i = 0; i < n; i++) {
        int f;
        cin >> f;
        if (f >= min and f <= max) {
            s++;
        }
    }
    cout << s << endl;
}