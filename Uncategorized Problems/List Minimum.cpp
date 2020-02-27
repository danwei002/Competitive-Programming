#include <bits/stdc++.h>

using namespace std;

int main() {
    int size;
    scanf("%d", &size);
    int f[size];
    for (int i = 0; i < size; i++) {
        scanf("%d", &f[i]);
    }
    
    int n = sizeof(f) / sizeof(f[0]);
    sort(f, f + n);
    for (int i = 0; i < size; i++) {
        printf("%d\n", f[i]);
    }
}