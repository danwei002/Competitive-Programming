#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m; scanf("%d%d", &n, &m);
    if (n >= 3 and m <= 4) {printf("%s\n", "TroyMartian");}
    
    if (n <= 6 and m >= 2) {printf("%s\n", "VladSaturnian");}
    
    if (n <= 2 and m <= 3) {printf("%s\n", "GraemeMercurian");}
    return 0;
}