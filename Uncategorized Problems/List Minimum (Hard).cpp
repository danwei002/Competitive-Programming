#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    long long a[n];
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    
    int N = sizeof(a) / sizeof(a[0]);
    sort(a, a + N);
    for (int i = 0; i < n; i++) {
        cout << a[i] << endl;
    }
}