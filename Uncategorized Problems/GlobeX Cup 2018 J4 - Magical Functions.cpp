#include <bits/stdc++.h>

using namespace std;


unsigned long long f(unsigned long long a, unsigned long long b, unsigned long long c, unsigned long long d, unsigned long long e, unsigned long long x) {
    if (x == 0) {
        return e;
    }
    return (a * f(a, b, c, d, e, x / b) + c * f(a, b, c, d, e, x / d)) % 1000000007;
}

int main() {
    unsigned long long a, b, c, d, e, N;
    scanf("%llu%llu%llu%llu%llu%llu", &a, &b, &c, &d, &e, &N);
    cout << f(a, b, c, d, e, N) % 1000000007 << endl;
}