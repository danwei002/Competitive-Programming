#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N; long long T;
    cin >> N >> T;
    int gen[N];
    int nxt[N];
    for (int i = 0; i < N; i++) {
        char c;
        cin >> c;
        if (c == '0') {gen[i] = 0;}
        else {gen[i] = 1;}
    }
    
    for (int i = 50; i >= 0; i--) {
        if ((T >> i) & 1) {
            long long l = (1LL << i) % N; long long l2 = (N - l) % N;
            for (int j = 0; j < N; j++) {
                nxt[j] = gen[(j + l) % N] ^ gen[(j + l2) % N];
            }
            for (int k = 0; k < N; k++) {gen[k] = nxt[k];}
        }
    }
    
    for (auto p: gen) {cout << p;}
    return 0;
}