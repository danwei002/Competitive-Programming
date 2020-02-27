#include <bits/stdc++.h>

using namespace std;

int main() {
    int a, b, c; scanf("%d%d%d", &a, &b, &c);
    if (a != 0 and b != 0 and c != 0) {printf("%s\n", "NO"); return 0;}
    if ((a == 0 and b == 0) or (a == 0 and c == 0) or (b == 0 and c == 0)) {printf("%s\n", "YES"); return 0;}
    if (a == 0) {
        if (b == 3 and c == 2) {printf("%s\n", "NO"); return 0;}
        else {printf("%s\n", "YES"); return 0;}
    }
    
    if (b == 0) {
        if (a == 3 and c == 1) {printf("%s\n", "NO"); return 0;}
        else {printf("%s\n", "YES"); return 0;}
    }
    
    if (c == 0) {
        if (a == 2 and b == 1) {printf("%s\n", "NO"); return 0;}
        else {printf("%s\n", "YES"); return 0;}
    }
    return 0;
}