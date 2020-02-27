#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll D, H;
int main() {
    scanf("%lld", &D);
    for (int i = 0; i < D; i++) {
        scanf("%lld", &H);
        if (H % 3LL == 0) {
            printf("%lld\n", (H / 3) * (H / 3) * (H / 3));
        } else if (H % 3LL == 1) {
            printf("%lld\n", (H / 3) * (H / 3) * ((H / 3) + 1));
        } else {
            printf("%lld\n", (H / 3) * ((H / 3) + 1) * ((H / 3) + 1));
        }
    }
    return 0;
}