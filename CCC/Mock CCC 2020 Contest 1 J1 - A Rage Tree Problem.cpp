#include <bits/stdc++.h>

using namespace std;

int main() {
    int N[4];
    for (int i = 0; i < 4; i++) {scanf("%d", &N[i]);}
    sort(N, N + 4);
    printf("%d\n%d\n", N[0], N[3]);
    return 0;
}