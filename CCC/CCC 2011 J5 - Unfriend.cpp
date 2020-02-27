#include <bits/stdc++.h>

using namespace std;

int main() {
    int N; scanf("%d", &N);
    int a[N]; 
    for (int i = 0; i <= N; i++) {a[i] = 1;}
    for (int i = 1; i < N; i++) {
        int b; scanf("%d", &b);
        a[b] = a[b] * (1 + a[i]);
    }
    printf("%d\n", a[N]);
    return 0;
}