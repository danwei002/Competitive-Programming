#include <bits/stdc++.h>

using namespace std;

double pi = 3.1415;
int main() {
    int radius; scanf("%d", &radius);
    while (radius != 0) {
        int ans = 0;
        for (int i = 1; i <= radius; i++) {ans += (int) sqrt((radius * radius - i * i)) + 1;}
        ans *= 4;
        printf("%d\n", ans + 1);
        scanf("%d", &radius);
    }
    return 0;
}