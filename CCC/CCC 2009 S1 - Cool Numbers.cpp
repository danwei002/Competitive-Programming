#include <bits/stdc++.h>

using namespace std;

int main() {
    long long int a, b;
    scanf("%lld", &a); scanf("%lld", &b);
    int cnt = 0;
    for (int i = sqrt(a); i <= sqrt(b); i++) {
        for (int j = cbrt(a); j <= cbrt(b); j++) {
            if (i * i == j * j * j) {
                cnt++;
            }
            
            if (j * j * j > i * i) {
                break;
            }
        }
    }
    cout << cnt;
}