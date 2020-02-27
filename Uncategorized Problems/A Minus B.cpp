#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    scanf("%d", &N);
    
    for (int i = 0; i < N; i++) {
        int a; int b;
        scanf("%d", &a);
        scanf("%d", &b);
        int c = a - b;
        cout << c << endl;
    }
}