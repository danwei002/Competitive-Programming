#include <bits/stdc++.h>

using namespace std;

int numCrys(int m, int x) {
    if (m >= 1) {
        int p = pow(5, m - 1);
        int l = x / p;
        if (l == 0 or l == 4) {
            return 0;
        } else if (l == 1 or l == 3) {
            return 1 * p + numCrys(m - 1, x % p);
        } else if (l == 2) {
            return 2 * p + numCrys(m - 1, x % p);
        }
    }
    return 0;
}

int main() {
    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; i++) {
        int m, x, y;
        scanf("%d%d%d", &m, &x, &y);
        if (y < numCrys(m, x)) {printf("%s\n", "crystal");}
        else {printf("%s\n", "empty");}
    }
    return 0;
}