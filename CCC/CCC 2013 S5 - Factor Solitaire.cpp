#include <bits/stdc++.h>

using namespace std;

int main() {
    long long N;
    scanf("%lld", &N);
    long long c = 0;
    while (N > 1) {
        for (long long i = N - 1; i >= 1; i--) {
            if (N % i == 0) {
                N -= i;
                c += N / i;
                break;
            }
        }
    }
    
    printf("%lld\n", c);
    return 0;
}