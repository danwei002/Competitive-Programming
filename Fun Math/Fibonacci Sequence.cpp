#include <bits/stdc++.h>

using namespace std;

unordered_map<unsigned long long, unsigned long long> mp;
unsigned long long fib(unsigned long long n) {
    if (mp.count(n)) {
        return mp[n];
    }
    
    unsigned long long k = n / 2;

    if (n % 2 == 0) {
        unsigned long long a = (fib(k) * fib(k) + fib(k - 1) * fib(k - 1)) % 1000000007;
        return mp[n] = a;
    } else {
        k = n / 2;
        unsigned long long a = (fib(k) * fib(k + 1) + fib(k - 1) * fib(k)) % 1000000007;
        return mp[n] = a;
    }
    
}

int main() {
    unsigned long long N;
    scanf("%llu", &N);
    mp[0] = 1; mp[1] = 1;
    cout << fib(N - 1) % 1000000007;
}