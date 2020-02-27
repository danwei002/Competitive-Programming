#include <bits/stdc++.h>

using namespace std;

int main() {
    long long n;
    scanf("%lld", &n);
    long long s = 0;
    while (n != 1) {
        if (n % 2LL == 1LL) {
            n = n * 3LL + 1LL;
        } else {
            n /= 2LL;
        }
        s++;
    }
    printf("%d\n", s);
    return 0;
}