#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, M;
    scanf("%d%d", &N, &M);
    
    for (int i = 0; i < N - 1; i++) {
        int n; scanf("%d", &n);
        if (n >= M) {printf("%s\n", "NO"); return 0;}
    }
    printf("%s\n", "YES");
    return 0;
}