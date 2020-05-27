#include <bits/stdc++.h>

using namespace std;

int main() {
    int S, M, L; scanf("%d%d%d", &S, &M, &L);
    if (S + 2 * M + 3 * L >= 10) {printf("%s\n", "happy");}
    else {printf("%s\n", "sad");}
    return 0;
}