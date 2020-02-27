#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        unsigned long long s;
        scanf("%llu", &s);
        if ((s & (s - 1)) == 0) {printf("%s\n", "T");}
        else {printf("%s\n", "F");}
    }
    return 0;
}