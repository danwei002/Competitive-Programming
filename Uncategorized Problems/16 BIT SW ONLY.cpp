#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        long long int A, B, P;
        scanf("%lld", &A);
        scanf("%lld", &B);
        scanf("%lld", &P);
        if (A * B == P) {
            cout << "POSSIBLE DOUBLE SIGMA" << endl;
        } else {
            cout << "16 BIT S/W ONLY" << endl;   
        }
    }
}