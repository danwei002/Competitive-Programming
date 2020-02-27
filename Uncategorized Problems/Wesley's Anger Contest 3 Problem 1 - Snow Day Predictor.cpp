#include <bits/stdc++.h>

using namespace std;

int T, D, P;
int main() {
    scanf("%d%d%d", &T, &D, &P);
    if ((T < -40 and D >= 15) or (T < -40 and P > 50) or (D >= 15 and P > 50)) {printf("%s\n", "YES");}
    else {printf("%s\n", "NO");}
    return 0;
}