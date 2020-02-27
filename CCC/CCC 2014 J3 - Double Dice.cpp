#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a = 100;
    int d = 100;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int A, D;
        cin >> A >> D;
        if (D < A) {
            d -= A;
        } else if (A < D) {
            a -= D;
        }
    }
    cout << a << endl << d;
}