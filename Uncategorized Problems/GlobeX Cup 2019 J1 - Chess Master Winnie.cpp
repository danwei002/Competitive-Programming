#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, M, A, B, C;
    scanf("%d%d%d%d%d", &N, &M, &A, &B, &C);
    
    int wl[N + 1];
    for (int i = 1; i <= N; i++) {
        scanf("%d", &wl[i]);
    }
    
    for (int i = 0; i < C; i++) {
        int face;
        scanf("%d", &face);
        if (wl[face] == 0) {
            M -= B;
        } else if (wl[face] == 1) {
            M += A;
        }
    }
    
    printf("%d\n", M);
}